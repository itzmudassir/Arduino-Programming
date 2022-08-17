#include<Servo.h>
// PROGRAMMED BY: Mudassir Nadeem

#include<LiquidCrystal_I2C.h>
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
LiquidCrystal_I2C lcd(0x27, 16, 2);




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
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  delay(2000);
  lcd.clear();
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
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Traffic Lights");
    lcd.setCursor(0, 1);
    lcd.print("ON");
    delay(1000);
    
    
    digitalWrite(r1, HIGH);
    digitalWrite(g2, HIGH);
    myservo1.write(90);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Right Side");
    lcd.setCursor(0, 1);
    lcd.print("GO");
    
    
    
    delay(10000);
    
    digitalWrite(r1, LOW);
    digitalWrite(g2, LOW);
    
    
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    myservo1.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wait");
    
    delay(2000);
  
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    
    
    digitalWrite(r2, HIGH);
    digitalWrite(g1, HIGH);
    myservo2.write(90);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Left Side");
    lcd.setCursor(0, 1);
    lcd.print("      GO");
   
    delay(10000);
    
    
    digitalWrite(r2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    myservo2.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wait");
    delay(2000);
    
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Traffic Lights");
    lcd.setCursor(0 , 1);
    lcd.print("OFF");
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
