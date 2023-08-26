#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);  // Set CE and CSN pins

int joy1XPin = A0;  // Joystick 1 X-axis analog input pin
int joy2YPin = A1;  // Joystick 2 Y-axis analog input pin

void setup() {
  // Initialize the RF24 module
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.setPALevel(RF24_PA_LOW);
}

void loop() {
  int joy1X = analogRead(joy1XPin);  // Read Joystick 1 X-axis value
  int joy2Y = analogRead(joy2YPin);  // Read Joystick 2 Y-axis value

  // Create a data payload with joystick values
  int payload[2];
  payload[0] = joy1X;
  payload[1] = joy2Y;

  // Send the payload wirelessly to the receiver
  radio.write(&payload, sizeof(payload));
}