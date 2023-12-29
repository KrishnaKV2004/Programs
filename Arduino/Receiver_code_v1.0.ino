/* Arduino Hand Gesture Control Mecanum Robot-Receiver
Version 1.0
by DIY Builder
Created 04 Jul 2023
*/

// Include necessary libraries
#include <RF24.h>
#include <SPI.h>

// Define motor pins
const int motorA1 = 2;
const int motorA2 = 3;
const int motorB1 = 4;
const int motorB2 = 5;
const int motorC1 = 6;
const int motorC2 = 9;
const int motorD1 = 10;
const int motorD2 = A0;

// Initialize variables for motor speed and joystick values
int Speed1 = 255;
int Speed2 = 0;
int xAxis = 0;
int yAxis = 0;
int buttonValue = 0;

// Create an instance of the RF24 radio class
RF24 radio(8, 7); // CE, CSN pins

// Define the address for communication
const byte address[6] = "00001"; // Address of the receiver

// Variables to keep track of time for data refreshing
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

// Define a structure to hold the joystick and button values
struct Data_Package {
  byte xValue;
  byte yValue;
  byte switchValue;
};
Data_Package data;

// Function to initialize setup configurations
void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  radio.begin(); // Initialize the RF24 radio
  radio.openReadingPipe(1, address); // Set the communication pipe
  radio.setAutoAck(false); // Disable auto acknowledgment
  radio.setDataRate(RF24_250KBPS); // Set data rate
  radio.setPALevel(RF24_PA_LOW); // Set power level
  radio.startListening(); // Start listening for incoming data
  resetData(); // Reset Axis and button values

  // Set motor pins as OUTPUT
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorC1, OUTPUT);
  pinMode(motorC2, OUTPUT);
  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);
}

// Function to continuously loop and control the robot
void loop() {
  currentTime = millis(); // Get the current time
  if (currentTime - lastReceiveTime > 500) {
    resetData(); // If no data received for a certain time, reset values
  }
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read data from the radio
    lastReceiveTime = millis(); // Update last receive time
    xAxis = data.xValue; // Update x-axis value
    yAxis = data.yValue; // Update y-axis value
    buttonValue = data.switchValue; // Update button value
  }

  // Print joystick and button values for debugging
  Serial.print("X: ");
  Serial.print(xAxis);
  Serial.print("\tY: ");
  Serial.print(yAxis);
  Serial.print("\tPress Count: ");
  Serial.println(buttonValue);

  // Call appropriate function based on the button value
  if (buttonValue == 0) {
    normalMode();
  } else if (buttonValue == 1) {
    partialMode();
  } else if (buttonValue == 2) {
    cornerMode();
  }
}

// Function to control the robot in normal mode
void normalMode() {
  if (xAxis > 180) {
    turnRight();
  } else if (xAxis < 80) {
    turnLeft();
  } else if (yAxis > 180) {
    moveForward();
  } else if (yAxis < 80) {
    moveBackward();
  } else {
    stop();
  }
}

// Function to control the robot in partial mode
void partialMode() {
  if (xAxis > 180) {
    moveLeft();
  } else if (xAxis < 80) {
    moveRight();
  } else {
    stop();
  }
}

// Function to control the robot in corner mode
void cornerMode() {
  if ((xAxis > 180) && (yAxis > 180)) {
    topRight();
  } else if ((xAxis < 80) && (yAxis > 180)) {
    topLeft();
  } else if ((xAxis > 180) && (yAxis < 80)) {
    buttomRight();
  } else if ((xAxis < 80) && (yAxis < 80)) {
    buttomLeft();
  } else {
    stop();
  }
}

// Functions to control robot movement in different directions
void moveForward() {
  analogWrite(motorA1, Speed1);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed1);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed1);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed1);
  digitalWrite(motorD2, LOW);
}

void moveBackward() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, HIGH);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, HIGH);
}

void turnRight() {
  analogWrite(motorA1, Speed1);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed1);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, HIGH);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, HIGH);
}

void turnLeft() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorC1, Speed1);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed1);
  digitalWrite(motorD2, LOW);
}

void moveRight() {
  analogWrite(motorA1, Speed1);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorC1, Speed1);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, HIGH);
}

void moveLeft() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorB1, Speed1);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, HIGH);
  analogWrite(motorD1, Speed1);
  digitalWrite(motorD2, LOW);
}

void topRight() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed1);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed1);
  digitalWrite(motorD2, LOW);
}

void topLeft() {
  analogWrite(motorA1, Speed1);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed1);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, LOW);
}

void buttomRight() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, HIGH);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, LOW);
}

void buttomLeft() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, HIGH);
}

void stop() {
  analogWrite(motorA1, Speed2);
  digitalWrite(motorA2, LOW);
  analogWrite(motorB1, Speed2);
  digitalWrite(motorB2, LOW);
  analogWrite(motorC1, Speed2);
  digitalWrite(motorC2, LOW);
  analogWrite(motorD1, Speed2);
  digitalWrite(motorD2, LOW);
}

void resetData() {
  xAxis = 127;
  yAxis = 127;
  buttonValue = 0;
}
