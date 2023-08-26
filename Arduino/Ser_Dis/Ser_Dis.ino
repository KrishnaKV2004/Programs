#include <Servo.h>

Servo myservo;  // create servo object to control the servo
int trigPin = 10;  // set the trig pin for the ultrasonic sensor
int echoPin = 12;  // set the echo pin for the ultrasonic sensor
int distance;  // variable to store the distance measured by the sensor

void setup() {
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  myservo.attach(9);  // attach the servo to pin 9
  pinMode(trigPin, OUTPUT);  // set the trig pin as an output
  pinMode(echoPin, INPUT);  // set the echo pin as an input
}

void loop() {
  digitalWrite(trigPin, LOW);  // set the trig pin to low
  delayMicroseconds(2);  // wait for 2 microseconds
  digitalWrite(trigPin, HIGH);  // set the trig pin to high
  delayMicroseconds(10);  // wait for 10 microseconds
  digitalWrite(trigPin, LOW);  // set the trig pin to low
  distance = pulseIn(echoPin, HIGH) / 58;  // calculate the distance based on the duration of the pulse
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 15) 
  {  // if an object is detected within 15cm
    myservo.write(90);  // turn the servo to 90 degrees
    delay(1000);  // wait for 1 second
    myservo.write(0);  // turn the servo back to 0 degrees
    delay(1000); 
    myservo.write(180);
    delay(1000);
    myservo.write(90);
    delay(1000); // wait for 1 second
  }
}