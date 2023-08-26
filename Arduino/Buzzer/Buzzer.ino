int buzzerPin = 9;   // Define the buzzer pin

void setup() {
  pinMode(buzzerPin, OUTPUT);   // Initialize the buzzer pin as output
}

void loop() {
  tone(buzzerPin, 1000);   // Play a 1000Hz tone on the buzzer
  delay(500);             // Wait for 500ms
  noTone(buzzerPin);       // Stop the tone
  delay(500);             // Wait for another 500ms
}