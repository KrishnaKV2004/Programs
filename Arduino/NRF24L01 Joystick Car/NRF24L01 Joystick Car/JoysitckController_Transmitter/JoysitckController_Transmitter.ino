//Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
//Joystick Car Transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(5,6); // CE, CSN
const byte address[6] = "00001";
char xyData[32] = "";
int joystick[2];
int buzz = 10;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz,LOW);
}
void loop() {
 
  joystick[0] = analogRead(A0);
  joystick[1] = analogRead(A2);
  
  radio.write( joystick, sizeof(joystick) );
}
