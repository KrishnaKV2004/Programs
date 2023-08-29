#include <DigiKeyboard.h>

void setup() {
  // Set up the keyboard
  DigiKeyboard.delay(2000);  // Delay for 2 seconds
  DigiKeyboard.sendKeyStroke(0);  // Release all keys
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Press Win + R
  DigiKeyboard.delay(1000); // Wait for the Run dialog to open
}

void loop() {
  // Nothing to do here
}