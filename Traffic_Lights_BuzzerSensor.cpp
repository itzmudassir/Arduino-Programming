// PROGRAMMED BY: Mudassir Nadeem

int r1 = 2;
int y1 = 3;
int g1 = 4;
int r2 = 5;
int y2 = 6;
int g2 = 7;
int reader = 11;
int buzzer = 8;



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
    
    delay(10000);
    
    digitalWrite(r1, LOW);
    digitalWrite(g2, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    
    delay(2000);
  
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(g1, HIGH);
   
    delay(10000);
    
    
    digitalWrite(r2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    delay(2000);
    
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
