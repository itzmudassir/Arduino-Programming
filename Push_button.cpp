#include <Arduino.h>
int pbutton = 8;
int pbutton1 = 13;
int L2 = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(pbutton, INPUT_PULLUP);
  pinMode(pbutton1, INPUT_PULLUP);
  pinMode(L2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead (pbutton1) == LOW){
    digitalWrite(L2,LOW);
  
  }
  if (digitalRead (pbutton) == LOW){
    digitalWrite(L2, HIGH);
  }
}
