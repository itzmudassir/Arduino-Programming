// PROGRAMMED BY: Mudassir Nadeem

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 7;

void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
}

void loop(){
  forward();
  delay(1000);
  stops();
  delay(1000);
  reverse();
  delay(1000);
  stops();
  delay(1000);
  right();
  delay(1000);
  stops();
  delay(1000);
  left();
  delay(1000);
  stops();
  delay(1000);
  
}

void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
}

void reverse(){
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
}

void right(){
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
}

void left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, HIGH);
}

void stops(){
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
}
