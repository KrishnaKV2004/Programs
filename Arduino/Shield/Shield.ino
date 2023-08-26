#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Set the maximum speed for each motor (0-255)
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
  // Move motors forward
  moveMotorsForward();
  delay(2000);  // Wait for 2 seconds

  // Stop motors
  stopMotors();
  delay(1000);  // Wait for 1 second

  // Move motors backward
  moveMotorsBackward();
  delay(2000);  // Wait for 2 seconds

  // Stop motors
  stopMotors();
  delay(1000);  // Wait for 1 second
}

void moveMotorsForward() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void moveMotorsBackward() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}