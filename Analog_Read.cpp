// PROGRAMMED BY: Mudassir Nadeem

int potPin = A0;
int red = 6;


int brightnes;
void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(red , OUTPUT);
}
// put your setup code here, to run once:



void loop() {
 float potRead = analogRead(potPin);
 int brightness =(255./1023.)*potRead;
  
  analogWrite( red, brightness);


  // put your main code here, to run repeatedly:

}
