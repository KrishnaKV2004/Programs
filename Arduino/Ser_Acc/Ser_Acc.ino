#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int xpin = A0;  // x-axis of the accelerometer connected to analog pin A0
int xval; // variables to store the values from the accelerometer
int xangle; // variables to store the angle to rotate the servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  xval = analogRead(xpin);  // read the y-axis value from the accelerometer

  // map the x-axis and y-axis values to servo angles
  xangle = map(xval, 0, 1023, 0, 180);

  myservo.write(xangle);  // set the servo angle based on the x-axis value
  delay(15);              // wait for the servo to move
}