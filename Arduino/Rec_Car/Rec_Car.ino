#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <AFMotor.h>
#include <Servo.h>

RF24 radio(7, 8); // CE and CSN Pins
const byte address[32] = "00001"; // Address for NRF24L01

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo steerServo;
int steerAngle = 90;

void setup()
{
    while (!Serial);
    Serial.begin(9600);

    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();

    

    

    steerServo.attach(9);
    steerServo.write(steerAngle);
}

void loop() 
{
  if(radio.available())
  {
    char data[2]={0};
    radio.read(&data, sizeof(data));
    Serial.println(data);

    if (data[0]=='S' && data[1]=='S')
    {
        stop_stop();
    }

    if (data[0]=='F' && data[1]=='S')
    {
        forward_stop();
    }

    if (data[0]=='B' && data[1]=='S')
    {
        backward_stop();
    }

    if (data[0]=='S' && data[1]=='L')
    {
        stop_left();
    }

    if (data[0]=='S' && data[1]=='R')
    {
        stop_right();
    }

    if (data[0]=='F' && data[1]=='L')
    {
        forward_left();
    }

    if (data[0]=='F' && data[1]=='R')
    {
        forward_right();
    }

    if (data[0]=='B' && data[1]=='L')
    {
        backward_left();
    }

    if (data[0]=='B' && data[1]=='r')
    {
        backward_right();
    }
  }
}

void forward_stop()
{
    steerAngle = 90;
    steerServo.write(steerAngle);

    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void backward_stop()
{
    steerAngle = 90;
    steerServo.write(steerAngle);

    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void stop_left()
{
    steerAngle = 180;
    steerServo.write(steerAngle);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);

}

void stop_right()
{
    steerAngle = 0;
    steerServo.write(steerAngle);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void forward_left()
{
    steerAngle = 180;
    steerServo.write(steerAngle);

    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void forward_right()
{
    steerAngle = 0;
    steerServo.write(steerAngle);

    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void backward_left()
{
    steerAngle = 180;
    steerServo.write(steerAngle);

    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void backward_right()
{
    steerAngle = 0;
    steerServo.write(steerAngle);

    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void stop_stop()
{
    steerAngle = 90;
    steerServo.write(steerAngle);

    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor3.setSpeed(0);
    motor4.setSpeed(0);

    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}