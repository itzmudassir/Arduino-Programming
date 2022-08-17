// PROGRAMMED BY: Mudassir Nadeem

//Read Value from The monitor and Assign colors according to the age.

int redPin = 9;  // Lights Pins are declared in this Section.
int bluePin = 10;
int greenPin = 11;


String j;    //Variables that are gonna used below.
String Username;
int Age;


String msg1 = "Please enter your good name: ";    //Messages are given in this Secttion.
String msg2 = "Please enter your age: ";
String msg3 = "Your colour is ";
String msg4 = "Hi, Mr.";
String msg5 = "I hope you are fine :)";



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.print(msg1);
  while (Serial.available() == 0) {

  }
  Username = Serial.readString();
  Serial.print(msg4);
  Serial.print(Username);
  Age = Serial.parseInt();
  Serial.print(msg2);
}
void loop() {


  while (Serial.available() == 0) {


  }

  Age = Serial.parseInt();

  if (Age > 0 && Age < 5) {


    Serial.println("Your colour is RED");
    digitalWrite(redPin, HIGH);
    Serial.print(msg2);
  }
  if (Age > 6 && Age < 10) {


    Serial.println("Your colour is GREEN");
    digitalWrite(greenPin, HIGH);
    Serial.print(msg2);
  }

}
