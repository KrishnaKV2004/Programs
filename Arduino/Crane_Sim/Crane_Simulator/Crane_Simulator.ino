// CRANE SIMULATOR V3
/*
  _____ _____            _   _ ______   
  / ____|  __ \     /\   | \ | |  ____|  
 | |    | |__) |   /  \  |  \| | |__   
 | |    |  _  /   / /\ \ | . ` |  __|       
 | |____| | \ \  / ____ \| |\  | |____       
  \_____|_|  \_\/_/    \_\_| \_|______|        

*/

// joystick 
// pins vrx -> A0 
// pins vry -> A1
// SWitch -> pin 2
// +5V
// GND

// 1.3 SH1106 I2C OLED display 
// SCK -> SCL
// SDA -> SDA
// +3V
// GND

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

const int VRx = A0;
const int VRy = A1;
const int SW = 2;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;

// 'cr0', 7x6px
const unsigned char cr0 [] PROGMEM = {0x38, 0x38, 0x44, 0x82, 0x82, 0xc6};
// 'cr1', 7x6px
const unsigned char cr1 [] PROGMEM = {0x38, 0x38, 0x44, 0x44, 0x44, 0x6c};
// 'box', 7x7px
const unsigned char box [] PROGMEM = {0xfe, 0x82, 0xaa, 0x92, 0xaa, 0x82, 0xfe};
// 'jerab', 15x10px
const unsigned char jerab [] PROGMEM = {0x40, 0x04, 0xff, 0xfe, 0x40, 0x04, 0xf8, 0x3e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xf9, 0x3e};
// 'pas1', 29x4px
const unsigned char pas1 [] PROGMEM = {
  0x5b, 0x6d, 0xb6, 0xd8, 0xe0, 0x18, 0x0c, 0x00, 0xe0, 0x18, 0x0c, 0x00, 0x5b, 0x6d, 0xb6, 0xd8};
// 'pas2', 29x4px
const unsigned char pas2 [] PROGMEM = {
  0x6d, 0xb6, 0xdb, 0x68, 0xe0, 0x18, 0x0c, 0x00, 0xe0, 0x18, 0x0c, 0x00, 0x6e, 0xdb, 0x6d, 0xb0};

byte pas=0;
byte vrychlost=1;
byte hrychlost=2;
byte x=63; // 7 default
byte y=25;
byte xbox=20;
byte ybox=56;
bool crane = false;
bool hold = false;
int i;
bool flipflop = false;
int v=0;
long lastDebounceTime = 0;  
long debounceDelay = 200;    

void setup()   {                
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay(); 
  display.display();
  // Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(2, INPUT_PULLUP);
}


void loop() {
display.clearDisplay();

if (pas<=5) display.drawBitmap(98, 59, pas1, 29, 4, WHITE); else display.drawBitmap(98, 59, pas2, 29, 4, WHITE);
pas=pas+1; 

if (pas>=10) pas=0;

// Joystick
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
 
if ((xPosition <= 500) && (x>hrychlost+7))     x=x-hrychlost;   // DOLEVA
if ((xPosition >= 522) && (x<128-hrychlost-8)) {x=x+hrychlost;   // DOPRAVA
                                                if ((x>=93) && (y>46)) y=46; // zvedne kdyz je nizko
                                               }
if ((yPosition <= 500) && (y>22+vrychlost))    y=y-vrychlost;   // NAHORU
if ((yPosition >= 522) && (y<64-vrychlost-13) && (x<=93)) y=y+vrychlost;  // DOLU pred pasem
if ((yPosition >= 522) && (y<64-vrychlost-17) && (x>=94)) y=y+vrychlost;  // DOLU za pasem   

//debounce
  if ( (millis() - lastDebounceTime) > debounceDelay) {
     if (SW_state == LOW) {
      lastDebounceTime = millis(); 
      crane = !crane;                            // UPNUTI/ODEPNUTI TLACITKEM
      if (hold==true) hold=false;   
     }
    else if (SW_state == LOW) {
      lastDebounceTime = millis();
      crane == false;
    }
  }

display.setCursor(10,0); display.print("CRANE SIMULATOR V3");
display.drawFastHLine(0,63,128, WHITE);       // podlaha  ___________
display.drawFastHLine(0,11,128, WHITE);       // vedeni jerabu
display.drawBitmap(x-7, 10, jerab, 15, 10, WHITE); // jerab
display.drawLine(x,20,x,y, WHITE);           // Lano

display.drawTriangle(102,40+v,108,40+v,105,45+v, flipflop);           // TRIANGLE
flipflop = !flipflop;
v=v+1;
if (v==5) v=-v;

if (crane == false) display.drawBitmap(x-3, y, cr0, 7, 6, WHITE); // Crane odepnuta;
if (crane == true)  display.drawBitmap(x-3, y, cr1, 7, 6, WHITE); // Crane upnuta;
                                                                   
if ((crane == false) && (x>=xbox) && (x<=xbox+7) && (y+6+1>=ybox))  i = i + 1; 
                                                                    else i=i-1;
if (i == -1) i=0;                                                                    
if ((crane == true) && (x>=xbox) && (x<=xbox+7) && (y+6+1>=ybox) && (i>=1))  hold = true;
if (i == 10) i=0;                                                                             
                                                                                                                                          
if ((hold == true) && (crane == true)) {xbox = x - 3;   // kdyz je upnuto pohybuje se bedna s lanem
                                        ybox = y+6;                                          
                  }                                                      
if ((hold == false) && (ybox<56) && (xbox<94)) ybox=ybox+1;   //  z je odepnute padani bedny dolu, rychlost padani                                            
if ((hold == false) && (ybox<=52) && (xbox>=94)) ybox=ybox+1;   //  z je odepnute padani bedny dolu, rychlost padani                                              
if ((hold == false) && (ybox>=52) && (xbox>=94))  { xbox=xbox+1;     // posuv doprava  
                                                    if (xbox == 150) {xbox = 10;
                                                    ybox=56; }
                                                    }                                   

display.drawBitmap(xbox, ybox, box, 7, 7, WHITE); // bedna

display.display();

  
}
