// PROGRAMMED BY: Mudassir Nadeem

float pi = 3.14;
int r = 2;
float v;
char c = 'A';
String msg1 = " circle of ";
String msg2 = " has radius ";
String msg3 = " = ";
int i =1;
int L11 = 11;
String msg4 = ". ";
int Waitx =500;
void setup() {
  Serial.begin(9600);
  pinMode(L11, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(L11, HIGH);
  v = pi*r*r;
  Serial.print(i);
  Serial.print(msg4);
  i = i+1;
  Serial.print(c);
  Serial.print(msg1);
  Serial.print(r);
  Serial.print(msg2);
  Serial.print(msg3);
  Serial.print(v);
  Serial.println(".");
  delay(Waitx);
  r= r+1;
  // put your main code here, to run repeatedly:

}
