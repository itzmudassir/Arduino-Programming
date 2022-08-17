// PROGRAMMED BY: Mudassir Nadeem

int rsPin = A0; //Rain Sensor Pin.
float rsRead;   // Variable to read the value of Rain Sensor.
int buzzer = 12;  //buzzer pin.
int relay = 11;  //digital Switch.
int L13 = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rsPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(L13, OUTPUT);

}

void loop() {
  rsRead = analogRead(rsPin);
  Serial.println(rsRead);
  if(rsRead > 0 && rsRead < 500){
    digitalWrite(relay, LOW);
  }
  else{
    digitalWrite(relay, HIGH);
    
  }
  if(rsRead > 501 && rsRead < 650){
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }
  if(rsRead > 651 && rsRead < 1023){
    digitalWrite(L13, HIGH);
  }
  else{
    digitalWrite(L13, LOW);
  }
  // put your main code here, to run repeatedly:

}
