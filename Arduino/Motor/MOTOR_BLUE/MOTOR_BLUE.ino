char receive = 0;
#define motorA_EN 9
#define motorA_IN1 8
#define motorA_IN2 7

void setup() {
  Serial.begin(9600);
  pinMode(motorA_EN, OUTPUT);
  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
}

void loop() {
  
  digitalWrite(motorA_IN1,LOW);
    digitalWrite(motorA_IN2,LOW);
  if(Serial.available()>0)
  {
    receive = Serial.read();
     Serial.print(receive);
     Serial.print("\n");
    if(receive=='F')
    {
    digitalWrite(motorA_IN1,HIGH);
    digitalWrite(motorA_IN2,LOW);
    }
    else if(receive='B')
    {
       digitalWrite(motorA_IN1,LOW);
       digitalWrite(motorA_IN2,HIGH);
    }
    else
    {
      digitalWrite(motorA_IN1,LOW);
      digitalWrite(motorA_IN2,LOW);
    }
  }
  
}

