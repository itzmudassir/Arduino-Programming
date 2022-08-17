// PROGRAMMED BY: Mudassir Nadeem

// Car project Using L298 Driver...

const int trig = 9;     //trig of distance sensor
const int echo = 8;     //echo of distance sensor

int buzzer = A1;
int Ll = A3;    //left Indicator of car
int Rl = A4;    //right indicator of car
int IN1 = 2;    //reverse pin of first Motor
int IN2 = 3;    //forward pin of first Motor
int IN3 = 4;    //reverse pin of 2nd Motor
int IN4 = 7;    //forward pin of 2nd Motor
int en1 = 5;    //First en pin to Control Speed
int en2 = 6;    //2nd en pin to Control Speed
int distance = 0;
int duration = 0;

int td = 1000;    //delay for trig Variable
int bd = 1000;    //delay for buzzer
int ld = 200;     //delay for lights
int Speed = 255;    //variable to control the speed of car



void setup() {
  pinMode(Ll, OUTPUT);
  pinMode(Rl, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(td);
  digitalWrite(trig, LOW);

 duration = pulseIn(echo, HIGH);
 distance = (duration/2) / 28.5;

 if (distance <= 15){
  digitalWrite(buzzer, HIGH);
  delay(bd);
  digitalWrite(buzzer, LOW);
  
  digitalWrite(Rl, HIGH);
  delay(ld);
  digitalWrite(Rl, LOW);
  digitalWrite(Rl, HIGH);
  delay(ld);
  digitalWrite(Rl, LOW);
  digitalWrite(Rl, HIGH);
  delay(ld);
  digitalWrite(Rl, LOW);
  digitalWrite(Rl, HIGH);
  delay(ld);
  digitalWrite(Rl, LOW);

  reverse();
  

  
  
  
 }

 
  // put your main code here, to run repeatedly:

}

void forward(){
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
}

void reverse(){
  analogWrite(en1, Speed);
  analogWrite(en2, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
}

void right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stops(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
