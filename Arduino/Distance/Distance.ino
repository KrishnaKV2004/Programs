// Define the pins for the ultrasonic sensor
#define trigPin 9
#define echoPin 10

// Define variables for the distance measurement
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Configure the pins for the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  // Send a pulse to the ultrasonic sensor to start a measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse returned by the ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}