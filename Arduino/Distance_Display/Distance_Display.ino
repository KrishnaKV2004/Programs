#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int trigPin = 2;  // Trigger pin for the ultrasonic sensor
const int echoPin = 3;  // Echo pin for the ultrasonic sensor

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);    // Set the trigger pin to low
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);   // Send a 10us pulse to trigger the ultrasonic sensor
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);  // Measure the pulse duration from the echo pin
  
  distance = duration * 0.034 / 2;   // Calculate the distance in centimeters
  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Distance:");
  display.setCursor(0, 20);
  display.println(distance);
  display.println("cm");
  display.display();
  
  delay(1000);  // Delay for 1 second before taking the next measurement
}