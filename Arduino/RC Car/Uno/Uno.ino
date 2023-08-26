#include <SoftwareSerial.h>
SoftwareSerial espSerial(2, 3);  // RX, TX pins for ESP8266 (connect RX to TX and TX to RX)

#include <RF24.h>
#include <AFMotor.h>

RF24 radio(9, 10);  // Set CE and CSN pins

AF_DCMotor motor1(1);  // Front left motor
AF_DCMotor motor2(2);  // Front right motor
AF_DCMotor motor3(3);  // Rear left motor
AF_DCMotor motor4(4);  // Rear right motor

int threshold = 550;  // Threshold for joystick deadzone

void setup() {
  Serial.begin(115200);

  // Set the speed of the motors
  motor1.setSpeed(255);  // Adjust the speed as required (0-255)
  motor2.setSpeed(255);  // Adjust the speed as required (0-255)
  motor3.setSpeed(255);  // Adjust the speed as required (0-255)
  motor4.setSpeed(255);  // Adjust the speed as required (0-255)

  // Initialize the RF24 module
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

  espSerial.begin(115200);  // Initialize ESP8266 serial communication
  delay(2000);
  espSerial.println("AT");  // Test ESP8266 communication
}

void loop() {
  if (radio.available()) {
    int payload[2];

    // Read the received payload
    radio.read(&payload, sizeof(payload));

    int joy1X = payload[0];  // Joystick 1 X-axis value
    int joy2Y = payload[1];  // Joystick 2 Y-axis value

    // Map joystick values to motor speed
    int speed = map(joy1X, 0, 1023, -255, 255);  // Mapping joystick 1 X-axis to speed
    int turn = map(joy2Y, 0, 1023, -255, 255);  // Mapping joystick 2 Y-axis to turn

    // Apply deadzone to joystick values
    if (abs(speed) < threshold) {
      speed = 0;
    }
    if (abs(turn) < threshold) {
      turn = 0;
    }

    // Control the motors based on joystick inputs
    motor1.setSpeed(abs(speed));
    motor2.setSpeed(abs(speed));
    motor3.setSpeed(abs(speed));
    motor4.setSpeed(abs(speed));

    if (speed >= 0) {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    }

    motor1.setSpeed(abs(turn));
    motor2.setSpeed(abs(turn));
    motor3.setSpeed(abs(turn));
    motor4.setSpeed(abs(turn));

    if (turn >= 0) {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
    } else {
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
    }
  }
}