// Pin definitions for the number pad
#define ROW_1_PIN 2
#define ROW_2_PIN 3
#define ROW_3_PIN 4
#define ROW_4_PIN 5
#define COL_1_PIN 6
#define COL_2_PIN 7
#define COL_3_PIN 8

// Keypad layout
char keys[4][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

void setup() {
  // Setup the number pad pins
  pinMode(ROW_1_PIN, OUTPUT);
  pinMode(ROW_2_PIN, OUTPUT);
  pinMode(ROW_3_PIN, OUTPUT);
  pinMode(ROW_4_PIN, OUTPUT);
  pinMode(COL_1_PIN, INPUT_PULLUP);
  pinMode(COL_2_PIN, INPUT_PULLUP);
  pinMode(COL_3_PIN, INPUT_PULLUP);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Check for button presses
  for (int row = 0; row < 4; row++) {
    digitalWrite(ROW_1_PIN, row == 0 ? LOW : HIGH);
    digitalWrite(ROW_2_PIN, row == 1 ? LOW : HIGH);
    digitalWrite(ROW_3_PIN, row == 2 ? LOW : HIGH);
    digitalWrite(ROW_4_PIN, row == 3 ? LOW : HIGH);
    delay(10);
    
    if (digitalRead(COL_1_PIN) == LOW) {
      char key = keys[row][0];
      Serial.print(key);
      delay(200);
    }
    if (digitalRead(COL_2_PIN) == LOW) {
      char key = keys[row][1];
      Serial.print(key);
      delay(200);
    }
    if (digitalRead(COL_3_PIN) == LOW) {
      char key = keys[row][2];
      Serial.print(key);
      delay(200);
    }
  }
}
