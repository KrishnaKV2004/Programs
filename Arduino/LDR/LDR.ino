int ldrPin = 9;   // assign the LDR sensor pin to a variable
int ledPin = 13;  // assign the LED pin to a variable

void setup() {
  pinMode(ldrPin, INPUT);  // set the LDR pin as input
  pinMode(ledPin, OUTPUT); // set the LED pin as output
  Serial.begin(9600);      // initialize serial communication for debugging
}

void loop() {
  int ldrReading = analogRead(ldrPin);  // read the LDR sensor value
  Serial.println(ldrReading);           // print the LDR sensor value for debugging

  if (ldrReading < 500) {    // if the LDR sensor value indicates low light
    digitalWrite(ledPin, HIGH);  // turn on the LED
  } else {
    digitalWrite(ledPin, LOW);   // turn off the LED
  }
  delay(100);  // wait for 100ms before taking another reading
}