// PROGRAMMED BY: Mudassir Nadeem

String msg1 = "LED has Analog Value = ";
String msg2 = ". ";

int led = 11;    //led pin
int v = 0;    //resistance for led
int b = 150;
int i = 1;

int msgdelay = 500;    //delay for message
int dely = 50;
int tdelay = 500;



void setup() {
  Serial.begin(9600);
  pinMode(led ,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  analogWrite(led , v);
  Serial.print(i);
  Serial.print(msg2);
  
  v = v +10;
  i = i +1;
  if ( i == 16){
    i = 1;
  }
  delay(msgdelay);
  Serial.print(msg1);
  Serial.println(v);
  delay(dely);
  if (v ==150){
    v = v - b;
    Serial.println("");s  
 
  }

  // put your main code here, to run repeatedly:

}
