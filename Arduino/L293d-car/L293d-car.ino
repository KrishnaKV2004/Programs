#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8); // CE and CSN Pins
const byte address[32] = "00001"; // Address for NRF24L01

 int motorA1 = 2;
 int motorA2 = 3;
 int motorB1 = 4;
 int motorB2 = 5;

Servo steerServo;
int steerAngle = 90;

void setup()
{

       while (!Serial);
        Serial.begin(9600);

  
    steerServo.attach(9);
    steerServo.write(steerAngle);
    pinMode(motorA1,OUTPUT);
    pinMode(motorA2,OUTPUT);
    pinMode(motorB1,OUTPUT);
    pinMode(motorB2,OUTPUT);
   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,LOW);
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();

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

   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,LOW);
   digitalWrite(motorB1,HIGH);
   digitalWrite(motorB2,LOW);


   
}

void backward_stop()
{
    steerAngle = 90;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,LOW);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,HIGH);
}

void stop_left()
{
    steerAngle = 180;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,LOW);

}

void stop_right()
{
    steerAngle = 0;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,LOW);
}

void forward_left()
{
    steerAngle = 180;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,LOW);
   digitalWrite(motorB1,HIGH);
   digitalWrite(motorB2,LOW);
}

void forward_right()
{
    steerAngle = 0;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,LOW);
   digitalWrite(motorB1,HIGH);
   digitalWrite(motorB2,LOW);
}

void backward_left()
{
    steerAngle = 180;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,LOW);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,HIGH);
}


void backward_right()
{
    steerAngle = 0;
    steerServo.write(steerAngle);

   digitalWrite(motorA1,LOW);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,HIGH);

}
void stop_stop()
{
    steerAngle = 90;
    steerServo.write(steerAngle);

   

   digitalWrite(motorA1,HIGH);
   digitalWrite(motorA2,HIGH);
   digitalWrite(motorB1,LOW);
   digitalWrite(motorB2,LOW);

}