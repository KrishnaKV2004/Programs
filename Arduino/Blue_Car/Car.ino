#include <Wire.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

// Define Bluetooth module pins
SoftwareSerial BTSerial(10, 11);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//  Pins For Ultrasonic Sensor
const int trigPin = 12;
const int echoPin = 13;

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  if (BTSerial.available()) {
    char command = BTSerial.read();
    handleBluetoothCommand(command);
  }

  if (getDistance() < 10) {
    stopMotors();
  }
}

void handleBluetoothCommand(char command) {
  switch (command) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'S':
      stopMotors();
      break;
  }
}

void moveForward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void turnRight() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void stopMotors() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}