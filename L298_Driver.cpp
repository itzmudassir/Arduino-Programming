// PROGRAMMED BY: Mudassir Nadeem

int f1 = 2;
int r1 = 3;
int f2 = 4;
int r2 = 5;
int L13 = 13;



void setup() {
  Serial.begin(9600);
  pinMode(f1, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(f2, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(L13, OUTPUT);

  Serial.print("OK");
  
  // put your setup code here, to run once:

}

void loop() {

  digitalWrite(f1, HIGH);
  delay(2000);
  digitalWrite(f1, LOW);
  
  digitalWrite(L13, HIGH);
  delay(1000);
  digitalWrite(L13, LOW);
  delay(500);
  
  digitalWrite(r1, HIGH);
  delay(2000);
  digitalWrite(r1, LOW);
  digitalWrite(L13, HIGH);
  delay(1000);
  digitalWrite(L13, LOW);
  delay(500);

  digitalWrite(f2, HIGH);
  delay(2000);
  digitalWrite(f2, LOW);
  
  digitalWrite(L13, HIGH);
  delay(1000);
  digitalWrite(L13, LOW);
  delay(500);
  
  digitalWrite(r2, HIGH);
  delay(2000);
  digitalWrite(r2, LOW);
  
  digitalWrite(L13, HIGH);
  delay(1000);
  digitalWrite(L13, LOW);
  delay(500);

  
  
  // put your main code here, to run repeatedly:

}
