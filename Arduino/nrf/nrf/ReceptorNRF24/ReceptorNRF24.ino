//  https://www.youtube.com/channel/UCKD9PvMAW0nYi681AZbSZSQ

#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
 
//pines CE y el CSN
RF24 radio(9,10);
 
//Variable con la dirección del canal que se va a leer
const byte direccion[6] = "00000";

Servo myservo;
int angulo =0;

void setup()
{
  //inicializamos el puerto serie
  Serial.begin(9600); 

  myservo.attach(3);
  
  //inicializamos el NRF24L01 
  radio.begin();

  
  //Abrimos el canal de Lectura
  radio.openReadingPipe(0, direccion);
  radio.setPALevel(RF24_PA_MIN);
  
  //empezamos a escuchar por el canal
  radio.startListening();
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);
 
}
 
void loop() {
  if (radio.available()){
      radio.read(&angulo, sizeof(angulo));
      Serial.println(angulo);
      myservo.write(angulo);
      
  }
 
}
