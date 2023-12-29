/* Arduino Gesture Control Mecanum Robot - Transmitter
Version 1.0
by DIY Builder
Created 04 Jul 2023
*/

#include <RF24.h>
#include <SPI.h>

// Define analog input pins for sensor axes and switch pin
const int xAxis = A3;
const int yAxis = A4;
const int zAxis = A5;
const int Switch = 6;

// Initialize variables for button states and press count
int buttonState = HIGH;       // Current state of the button
int lastButtonState = HIGH;   // Previous state of the button
int pressCount = 0;           // Counter for button presses

// Create an instance of the RF24 radio class
RF24 radio(1, 2);             // CE, CSN pins

// Define the address for communication
const byte address[6] = "00001"; 

// Define a structure to hold the joystick and button values
struct Data_Package {
  byte xValue;
  byte yValue;
  byte switchValue;
};
Data_Package data;

// Function to initialize setup configurations
void setup() {
  Serial.begin(115200);       // Initialize serial communication for debugging
  radio.begin();              // Initialize the RF24 radio
  radio.openWritingPipe(address); // Set the communication pipe for writing
  radio.setAutoAck(false);     // Disable auto acknowledgment
  radio.setDataRate(RF24_250KBPS); // Set data rate
  radio.setPALevel(RF24_PA_LOW); // Set power level

  pinMode(Switch, INPUT_PULLUP); // Set switch pin as input with internal pull-up resistor
}

// Function to continuously loop and send data
void loop() {
  buttonState = digitalRead(Switch); // Read the current state of the button

  // Check if the button is pressed and was not pressed before
  if (buttonState == LOW && lastButtonState == HIGH) {
    pressCount++; // Increment the button press count
    Serial.print("Button pressed! Count: ");
    Serial.println(pressCount); // Print the current button press count
    if (pressCount > 2) {
      pressCount = 0;
      Serial.print("Count reset to 0");
    }
  }

  lastButtonState = buttonState; // Save the current button state for the next iteration
  delay(10); // Delay to debounce the button (adjust as needed)

  // Map analog joystick values to byte values and update the data structure
  data.xValue = map(analogRead(xAxis), 400, 600, 0, 255);
  data.yValue = map(analogRead(yAxis), 400, 600, 0, 255);
  data.switchValue = pressCount;

  // Send data to the receiver
  radio.write(&data, sizeof(Data_Package));
}
