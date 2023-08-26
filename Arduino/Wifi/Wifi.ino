#include <ESP8266WiFi.h>

const char* ssid = "Krishna";     // Replace with your Wi-Fi network SSID
const char* password = "2004"; // Replace with your Wi-Fi network password

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // Connect to Wi-Fi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Wi-Fi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here
}