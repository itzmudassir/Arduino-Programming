// PROGRAMMED BY: Mudassir Nadeem


int lightPen = A0; //LDR Sensor
int lightVal;      //Variable to read the value of LDR Sensor

int redPin = 9;    //Red Light
int greenPin = 11; //Green Light
int bluePin = 10;  //Blue Light

int Blink = 3;     // Variable to blink Light
int c;             // counter Variable for repitations
int dv = 250;      //Delay for the value of LDR to be printed
int dl = 250;      //Delay for the Lights

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(lightPen); //Reading the Value of LDR Sensor
  Serial.println(lightVal);
  delay(dv);
  if (lightVal > 800 && lightVal < 1023) {
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      blue();
    }
    for (c = 1; c <= 3; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      pink();
    }

  }
  if (lightVal > 600 && lightVal < 798) {
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      green();

    }
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      orange();

    }
  }
  if (lightVal > 400 && lightVal < 598) {
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);

      red();
    }
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      cyan();

    }
  }
  if (lightVal > 10 && lightVal < 398) {
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      blue();
    }
    for (c = 1; c <= Blink; c = c + 1) {
      lightVal = analogRead(lightPen);
      Serial.println(lightVal);
      analogWrite(redPin , 230);
      analogWrite(greenPin , 126);
      analogWrite(bluePin , 34);
      delay(dl);
      analogWrite(redPin , 0);
      analogWrite(greenPin , 0);
      analogWrite(bluePin , 0);
      delay(dl);
    }
  }
}

void pink() {
  analogWrite(redPin , 192);
  analogWrite(greenPin , 57);
  analogWrite(bluePin , 43);
  delay(dl);
  analogWrite(redPin , 0);
  analogWrite(greenPin , 0);
  analogWrite(bluePin , 0);
  delay(dl);
}

void orange() {
  analogWrite(redPin , 211);
  analogWrite(greenPin , 84);
  analogWrite(bluePin , 0);
  delay(dl);
  analogWrite(redPin , 0);
  analogWrite(greenPin , 0);
  analogWrite(bluePin , 0);
  delay(dl);
}

void cyan() {
  analogWrite(redPin , 22);
  analogWrite(greenPin , 160);
  analogWrite(bluePin , 133);
  delay(dl);
  analogWrite(redPin , 0);
  analogWrite(greenPin , 0);
  analogWrite(bluePin , 0);
  delay(dl);
}

void blue() {
  digitalWrite(redPin , LOW);
  digitalWrite(greenPin , LOW);
  digitalWrite(bluePin , HIGH);
  delay(dl);
  digitalWrite(bluePin, LOW);
  delay(dl);

}

void green() {
  digitalWrite(redPin , LOW);
  digitalWrite(bluePin , LOW);
  digitalWrite(greenPin , HIGH);
  delay(dl);
  digitalWrite(greenPin, LOW);
  delay(dl);
}

void red() {
  digitalWrite(greenPin , LOW);
  digitalWrite(bluePin , LOW);
  digitalWrite(redPin , HIGH);
  delay(dl);
  digitalWrite(redPin, LOW);
  delay(dl);
}
