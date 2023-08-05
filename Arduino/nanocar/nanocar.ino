#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // NRF24L01 pins (CE, CSN)
const byte address[6] = "00001";

int joy1YPin = A0; // Joystick 1 Y-axis analog pin
int joy2XPin = A1; // Joystick 2 X-axis analog pin

int joy1YVal, joy2XVal;

void setup() {
 
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // Read joystick values
  joy1YVal = analogRead(joy1YPin);
  joy2XVal = analogRead(joy2XPin);

  // Map joystick values to desired range
  int mappedJoy1Y = map(joy1YVal, 0, 1023, -255, 255);
  int mappedJoy2X = map(joy2XVal, 0, 1023, -255, 255);

  // Prepare data packet
  char data[2];
  
  if (mappedJoy1Y > 250) 
  {
    data[0] = 'F'; // Forward
  } 
if (mappedJoy1Y < -250) 
{
    data[0] = 'B'; // Backward
  } 
if((mappedJoy1Y<250)&&(mappedJoy1Y>-250))
  {
    data[0] = 'S'; // Stop
  }
  
  if (mappedJoy2X > 250) 
   {
    data[1] = 'R'; // Right
  }
  if (mappedJoy2X < -250) 
  {
    data[1] = 'L'; // Left
  } 
  if((mappedJoy2X<250)&&(mappedJoy2X>-250)) 
  {
    data[1] = 'S'; // Straight
  }
 
  // Send data packet
  radio.write(&data, sizeof(data));
  
}
