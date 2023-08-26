#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // NRF24L01 pins (CE, CSN)
const byte address[32] = "00001";


void setup() {
  while (!Serial);
    Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
 // Receive data packet
  if(radio.available())
  {
  char data[2]={0};
  radio.read(&data, sizeof(data));
  Serial.println(data);
  }
}
