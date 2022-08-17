// PROGRAMMED BY: Mudassir Nadeem

#include<Servo.h>
int r1 = 2;
int y1 = 3;
int g1 = 4;
int r2 = 5;
int y2 = 6;
int g2 = 7;
int reader = 11;
int buzzer = 8;
Servo myservo1;
Servo myservo2;




void setup() {
  Serial.begin(9600);
  
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(reader, INPUT);
  myservo1.attach(10);
  myservo2.attach(9);
  digitalWrite(buzzer, HIGH);
  delay(2000);
  digitalWrite(buzzer, LOW);
  delay(2000);
  
  Serial.println("OK");
  // put your setup code here, to run once:

}

void loop() {
  if (digitalRead(reader) == LOW)
  {
    digitalWrite(r1, HIGH);
    digitalWrite(g2, HIGH);
    myservo1.write(90);
    
    delay(3000);
    
    digitalWrite(r1, LOW);
    digitalWrite(g2, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    myservo1.write(0);
    
    delay(1000);
  
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(g1, HIGH);
    myservo2.write(90);
   
    delay(3000);
    
    
    digitalWrite(r2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    myservo2.write(0);
    delay(1000);
    
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
    delay(2000);
  }
  else
  {
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(g2, LOW);
  }
  

  Serial.println("DONE");
  
  // put your main code here, to run repeatedly:

}
