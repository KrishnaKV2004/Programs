#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

byte uid[] = {0x12, 0x34, 0x56, 0x78}; // replace with the UID of your card
bool cardDetected = false;
int ledPin = 13; // the LED is connected to digital pin 13

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  // reset the card detection flag
  cardDetected = false;

  // check if a new card is present
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // compare the card's UID with the one we're looking for
    if (rfid.uid.size == 4 &&
        rfid.uid.uidByte[0] == uid[0] &&
        rfid.uid.uidByte[1] == uid[1] &&
        rfid.uid.uidByte[2] == uid[2] &&
        rfid.uid.uidByte[3] == uid[3]) {
      // card with matching UID detected
      cardDetected = true;
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  // blink the LED if the card was detected
  if (cardDetected) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
