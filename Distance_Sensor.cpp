// PROGRAMMED BY: Mudassir Nadeem

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trig = 13;
const int echo = 12;
int distance = 0;
int duration = 0;
int L2 = 2;
int L3 = 3;
int L4 = 4;
int L5 = 5;
int L6 = 6;
int L7 = 7;
int L8 = 8;
int L9 = 9;
int L10 = 10;
int L11 = 11;
int L12 = 12;


void setup() {
  Serial.begin(9600);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  pinMode(L9, OUTPUT);
  pinMode(L10, OUTPUT);
  pinMode(L11, OUTPUT);
  pinMode(L12, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  delay(2000);
  lcd.clear();

  Serial.println("OK");
  
}

void loop () {
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(echo, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 28.5;

  if (distance <= 30)
  {
   digitalWrite(L2, HIGH); 
  }
  else
  {
   digitalWrite(L2, LOW);
  }

  if (distance <= 28)
  {
   digitalWrite(L3, HIGH); 
  }
  else
  {
   digitalWrite(L3, LOW);
  }

  if (distance <= 25)
  {
   digitalWrite(L4, HIGH); 
  }
  else
  {
   digitalWrite(L4, LOW);
  }

  if (distance <= 22)
  {
   digitalWrite(L5, HIGH); 
  }
  else
  {
   digitalWrite(L5, LOW);
  }

  if (distance <= 20)
  {
   digitalWrite(L6, HIGH); 
  }
  else
  {
   digitalWrite(L6, LOW);
  }

  if (distance <= 18)
  {
   digitalWrite(L7, HIGH); 
  }
  else
  {
   digitalWrite(L7, LOW);
  }

  if (distance <= 16)
  {
   digitalWrite(L8, HIGH); 
  }
  else
  {
   digitalWrite(L8, LOW);
  }

  if (distance <= 14)
  {
   digitalWrite(L9, HIGH); 
  }
  else
  {
   digitalWrite(L9, LOW);
  }

  if (distance <= 12)
  {
   digitalWrite(L10, HIGH); 
  }
  else
  {
   digitalWrite(L10, LOW);
  }

  if (distance <= 10)
  {
   digitalWrite(L11, HIGH); 
  }
  else
  {
   digitalWrite(L11, LOW);
  }

  if (distance <= 8)
  {
   digitalWrite(L12, HIGH); 
  }
  else
  {
   digitalWrite(L12, LOW);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(distance);
  lcd.println("cm");
  
  Serial.print(distance);
  Serial.println("cm");
}
