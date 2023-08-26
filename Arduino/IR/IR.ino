int irSensorPin = 3; // define the IR sensor pin
 // define the built-in LED pin

void setup() {
  pinMode(irSensorPin, INPUT); // set the IR sensor pin as input
  pinMode(LED_BUILTIN, OUTPUT); // set the LED pin as output
}

void loop() {
  int sensorValue = digitalRead(irSensorPin); // read the sensor value
  
  if (sensorValue == HIGH) { // if an object is detected
    digitalWrite(LED_BUILTIN, LOW); // turn on the LED
  } else {
    digitalWrite(LED_BUILTIN, HIGH); // turn off the LED
  }
}
