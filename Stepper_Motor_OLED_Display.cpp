// PROGRAMMED BY: Mudassir Nadeem

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


int Pin1 = 10;//IN1 is connected to 10
int Pin2 = 11;//IN2 is connected to 11
int Pin3 = 12;//IN3 is connected to 12
int Pin4 = 13;//IN4 is connected to 13
int switchCW  = 2; //define input pin for CW push button
int switchStop = 3; //define input pin for Stop push button
int switchCCW = 4; //define input pin for CCW push button


int pole1[] = {0, 0, 0, 0, 0, 1, 1, 1, 0}; //pole1, 8 step values
int pole2[] = {0, 0, 0, 1, 1, 1, 0, 0, 0}; //pole2, 8 step values
int pole3[] = {0, 1, 1, 1, 0, 0, 0, 0, 0}; //pole3, 8 step values
int pole4[] = {1, 1, 0, 0, 0, 0, 0, 1, 0}; //pole4, 8 step values


int poleStep = 0;
int  dirStatus = 3;// stores direction status 3= stop (do not change)

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  pinMode(Pin1, OUTPUT);//define pin for ULN2003 in1
  pinMode(Pin2, OUTPUT);//define pin for ULN2003 in2
  pinMode(Pin3, OUTPUT);//define pin for ULN2003 in3
  pinMode(Pin4, OUTPUT);//define pin for ULN2003 in4

  pinMode(switchCW, INPUT_PULLUP); // CW push button pin as input
  pinMode(switchStop, INPUT_PULLUP); //Stop push button pin as input
  pinMode(switchCCW, INPUT_PULLUP); //CCW push button pin as input

}
void loop()
{

  if (digitalRead(switchCCW) == LOW)
  {
    dirStatus = 1;
    display.clearDisplay();
    
    
    clockwise();
  } else if (digitalRead(switchCW) == LOW)
  {
    dirStatus  = 2;
    display.clearDisplay();
    anticlockwise();
    
    
  } else if (digitalRead(switchStop) == LOW)
  {
    dirStatus = 3;
    display.clearDisplay();
    stops();
    
    
  }
  if (dirStatus == 1) {
    poleStep++;
    driveStepper(poleStep);
  } else if (dirStatus == 2) {
    poleStep--;
    driveStepper(poleStep);
  } else {
    driveStepper(8);
  }
  if (poleStep > 7) {
    poleStep = 0;
  }
  if (poleStep < 0) {
    poleStep = 7;
  }
  delay(1);

}// loop



/*
   @brief sends signal to the motor
   @param "c" is integer representing the pol of motor
   @return does not return anything

   www.Robojax.com code June 2019
*/
void driveStepper(int c)
{
  digitalWrite(Pin1, pole1[c]);
  digitalWrite(Pin2, pole2[c]);
  digitalWrite(Pin3, pole3[c]);
  digitalWrite(Pin4, pole4[c]);
}//driveStepper end here

void clockwise(void) {
  
  
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);            // Start at top-left corner
  display.println(F("Stepper Motor Control"));
  display.display();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(10,25);            // Start at top-left corner
  display.println(F("ClOCKWISE"));
  display.display();
  delay(2000);
}
void anticlockwise(void) {
  
  
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);            // Start at top-left corner
  display.println(F("Stepper Motor Control"));
  display.display();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(10,15);            // Start at top-left corner
  display.println(F("Anti"));
  display.display();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(10,35);            // Start at top-left corner
  display.println(F("Clockwise"));
  display.display();
  
  
  delay(2000);
}
void stops(void) {
  
  
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);            // Start at top-left corner
  display.println(F("Stepper Motor Control"));
  display.display();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(25,25);            // Start at top-left corner
  display.println(F("STOP"));
  display.display();
  delay(2000);
}
