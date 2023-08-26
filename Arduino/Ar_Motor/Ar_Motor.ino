#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  long duration, distance;
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 10) { // Adjust the threshold distance as per your requirement
    activateBuzzer();
  } else {
    stopBuzzer();
  }
  
  delay(500); // Adjust the delay as per your requirement
}

void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}

void stopBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);
}