// PROGRAMMED BY: Mudassir Nadeem

int L2 = 2;
int reader = 3;


void setup() {
  Serial.begin(9600);
  
  pinMode(L2, OUTPUT);
  pinMode(reader, INPUT);
  
  Serial.println("OK");
  // put your setup code here, to run once:

}

void loop() {
  int sensor = digitalRead(reader);
  if (sensor == LOW)
  {
    digitalWrite(L2, HIGH);
    delay(10000);
  }
  else
  {
    digitalWrite(L2, LOW);
  }

  Serial.println("DONE");
  // put your main code here, to run repeatedly:

}
