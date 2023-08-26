//  https://www.youtube.com/channel/UCKD9PvMAW0nYi681AZbSZSQ

#include <SPI.h>  
#include <RF24.h>


 
 RF24 radio(9, 10); // CE, CSN
 
 const byte direccion[6] = "00000";
 
void setup() {

  radio.begin();
  Serial.begin(9600);
 
   radio.openWritingPipe(direccion);
   radio.setPALevel(RF24_PA_MIN);
   radio.stopListening();
}
 
void loop() {
  
  int lecturaADC = analogRead(A0);
  int angulo = map(lecturaADC,0, 1023, 0,180);
  Serial.println(angulo);
  radio.write(&angulo, sizeof(angulo));
  delay(50); 
  
}
