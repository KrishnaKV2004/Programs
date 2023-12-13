#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address (usually 0x27 or 0x3F)
// You can use the I2C scanner to find the correct address
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // initialize with the I2C addr 0x27, 16 columns and 2 rows
  lcd.init();
 

  // Print a message to the LCD.
  lcd.print("Hello, Krishna");
}

void loop() {
  // Set the cursor to the beginning of the second line
  lcd.setCursor(0, 1);

  // Print the current millis value (uptime)
  lcd.print("Millis: ");
  lcd.print(millis() / 1000); // convert millis to seconds

  delay(500); // Wait for a second
  lcd.scrollDisplayLeft();
}
