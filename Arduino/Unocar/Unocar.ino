#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial espSerial(10, 11); // ESP01 pins (RX, TX)
AF_DCMotor motor1(1); // Motor 1 connected to M1-M2 of Motor Shield
AF_DCMotor motor2(2); // Motor 2 connected to M3-M4 of Motor Shield

void setup() {
  Serial.begin(9600);
  espSerial.begin(115200);
  pinMode(7, OUTPUT); // Motor Shield power enable pin
  digitalWrite(7, HIGH); // Enable Motor Shield power
  motor1.setSpeed(255); // Set maximum motor speed
  motor2.setSpeed(255); // Set maximum motor speed
}

void loop() {
  if (espSerial.available()) {
    char command = espSerial.read();

    // Control motors based on received command
    if (command == 'F') {
      forward();
    } if (command == 'B') {
      backward();
    } if (command == 'L') {
      left();
    } if (command == 'R') {
      right();
    } if (command == 'S') {
      stop();
    }
  }
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void right() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
