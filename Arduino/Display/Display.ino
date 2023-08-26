#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize with the I2C address of the OLED display

  // Clear the buffer
  display.clearDisplay();

  // Set text size
  display.setTextSize(1);

  // Set text color to white
  display.setTextColor(SSD1306_WHITE);

  // Print "Hello"
  display.setCursor(0,0);
  display.println("Hello");

  // Display the text
  display.display();
}

void loop() {
  // Do nothing
}
