#include <Servo.h>

//  Defining Pins

#define trigPin 10
#define echoPin 12
#define servoPin 9

//  Creating Object Servo

Servo servo;

//  Creating Variables

int angle = 0;  // servo position in degrees
long duration;
int distance;

void setup()
{
    //  Serial Monitor With Baud Rate 9600
    Serial.begin(9600);
    servo.attach(servoPin);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    servo.write(0);

    //  Generating Ultrasonic Pulse

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    //  Reading Duration By Echo Pin

    duration = pulseIn(echoPin, HIGH);

    //  Calculating Distance By Speed Of Sound

    distance = duration * 0.034/2;

    //  Printing Distance On Serial Monitor

    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.print(" cm");

    if (distance < 10)
    {
      for (angle=0; angle<=180; angle++)
      {
        servo.write(angle);
      }
      for (angle=180; angle>=0; angle--)
      {
        servo.write(angle);
      }
    }
}