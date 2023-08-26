#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

// Motor Shield initialization
AF_DCMotor motor1(1); // Motor 1 is connected to M1
AF_DCMotor motor2(2); // Motor 2 is connected to M2
AF_DCMotor motor3(3); // Motor 3 is connected to M3
AF_DCMotor motor4(4); // Motor 4 is connected to M4

// Servo setup
Servo steeringServo; // Create a servo object to control the steering
int steeringAngle = 90; // Initial angle for steering (straight ahead)

// Bluetooth module setup
char val;

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  steeringServo.attach(9); // Attach the servo to pin 9
  steeringServo.write(steeringAngle); // Set initial steering angle (straight ahead)
}

void loop() {
  while (Serial.available()>0){
    val = Serial.read();
    Serial.print(val);
}
  // Move the car based on the received command
  if (val == 'F')
  {
    forward();
  }
  if (val == 'B')
  {
    backward();
  }
  if (val == 'R')
  {
    right();
  }
  if (val == 'L')
  {
    left();
  }
  if (val == 'S')
  {
    stop();
  }
}

void forward() {
  motor1.setSpeed(255); // Set the speed for all motors
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD); // Motors move forward
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward() {
  motor1.setSpeed(255); // Set the speed for all motors
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(BACKWARD); // Motors move backward
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void right() {
  steeringAngle = 180; // Adjust the angle for right turn (example: 90 degrees)
  steeringServo.write(steeringAngle); // Set the servo angle for right turn

  // Reduce the speed of the motors on one side to make the car turn smoothly
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD); // Motors move forward
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void left() {
  steeringAngle = 0; // Adjust the angle for left turn (example: 0 degrees)
  steeringServo.write(steeringAngle); // Set the servo angle for left turn

  // Reduce the speed of the motors on one side to make the car turn smoothly
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  motor1.run(FORWARD); // Motors move forward
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void stop() {
  motor1.setSpeed(0); // Set speed to zero to stop the motors
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);

  motor1.run(RELEASE); // Release the motors to stop them
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
