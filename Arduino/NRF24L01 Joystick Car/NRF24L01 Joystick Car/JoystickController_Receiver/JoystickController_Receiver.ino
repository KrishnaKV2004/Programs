//Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
//Joystick Car Receiver

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define enA A5  
#define in1 6
#define in2 7
#define enB A3   
#define in3 2
#define in4 4
 
RF24 radio(9,10); // CE, CSN
const byte address[6] = "00001";
char receivedData[32] = "";
int  xAxis, yAxis;
int motorSpeedA = 0;
int motorSpeedB = 0;
int joystick[2]; 
 
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  
 
}
void loop() {
 
  if (radio.available()) {   // If the NRF240L01 module received data
     
      radio.read( joystick, sizeof(joystick) );
 
    radio.read(&receivedData, sizeof(receivedData));
    yAxis = joystick[0];
    xAxis = joystick[1];
    
    Serial.println(yAxis);
    Serial.println(xAxis);
 
  }
  
  if (yAxis < 470) {
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
 
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
 
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
 
  if (xAxis > 550) {
    
    int xMapped = map(xAxis, 550, 0, 0, 255);
    
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis < 470) {
    
    int xMapped = map(xAxis, 470, 1023, 0, 255);
    
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }
  
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
