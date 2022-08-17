// PROGRAMMED BY: Mudassir Nadeem

#include <Arduino.h>
int potPin = A0;
int lastPotValue;
int potVal;
int voltage;
int L2 = 2;
int L3 = 3;
int L4 = 4;
int L5 = 5;
int L6 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);

  
  // put your setup code here, to run once:
}

void loop() {
  potVal = analogRead(potPin);
  voltage = potVal/200;
  

  if(voltage != lastPotValue)
  {
    // enter switch case
    switch(voltage)
    {
      case 0:
        Serial.println("Very Low");
        digitalWrite(L2, HIGH);
        digitalWrite(L3, LOW);
        digitalWrite(L4, LOW);
        digitalWrite(L5, LOW);
        digitalWrite(L6, LOW);
        break;
      case 1:
        Serial.println("Low");
        digitalWrite(L2, LOW);
        digitalWrite(L3, HIGH);
        digitalWrite(L4, LOW);
        digitalWrite(L5, LOW);
        digitalWrite(L6, LOW);
        break;
      case 2:
        Serial.println("Moderate");
        digitalWrite(L2, LOW);
        digitalWrite(L3, LOW);
        digitalWrite(L4, HIGH);
        digitalWrite(L5, LOW);
        digitalWrite(L6, LOW);
        break;
      case 3:
        Serial.println("High");
        digitalWrite(L2, LOW);
        digitalWrite(L3, LOW);
        digitalWrite(L4, LOW);
        digitalWrite(L5, HIGH);
        digitalWrite(L6, LOW);
        break;
      case 4:
        Serial.println("Extreme");
        digitalWrite(L2, LOW);
        digitalWrite(L3, LOW);
        digitalWrite(L4, LOW);
        digitalWrite(L5, LOW);
        digitalWrite(L6, HIGH);
        break;
      default:
        Serial.println("error!");
        digitalWrite(L2, LOW);
        digitalWrite(L3, LOW);
        digitalWrite(L4, LOW);
        digitalWrite(L5, LOW);
        digitalWrite(L6, LOW);

        break;
    }
    lastPotValue = voltage;
    
  }



  // put your main code here, to run repeatedly:
}
