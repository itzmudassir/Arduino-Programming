// PROGRAMMED BY: Mudassir Nadeem

int LEDState=0;
int LEDState1=0;
int LEDPin=4;
int LEDPin1=5;
int buttonPin=2;
int buttonPin1=3;
int buttonNew;
int buttonNew1;
int buttonOld=1;
int buttonOld1=1;
int dt=100;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LEDPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(LEDPin1, OUTPUT);
pinMode(buttonPin1, INPUT_PULLUP);
 
}
 
void loop() {
buttonNew=digitalRead(buttonPin);
buttonNew1=digitalRead(buttonPin1);
if(buttonOld==0 && buttonNew==1){
  if (LEDState==0){
    digitalWrite(LEDPin,HIGH);
    LEDState=1;
  }
  else{
    digitalWrite(LEDPin, LOW);
    LEDState=0;
  }
}
if(buttonOld1==0 && buttonNew1==1){
  if (LEDState1==0){
    digitalWrite(LEDPin1,HIGH);
    LEDState1=1;
  }
  else{
    digitalWrite(LEDPin1, LOW);
    LEDState1=0;
  }
}
buttonOld=buttonNew;
buttonOld1=buttonNew1;
delay(dt);

}
