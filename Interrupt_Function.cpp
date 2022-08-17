// PROGRAMMED BY: Mudassir Nadeem


#include <Arduino.h>

#include <TimerOne.h>
String LEDStatus="OFF";
int YellowLED=3;
int RedLED=2;
 
void setup() 
{
  // Initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  pinMode(YellowLED, OUTPUT);    
  pinMode(RedLED,OUTPUT);
  
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt( BlinkYellow ); 
  Serial.begin(9600);
}
 
void loop()
{
digitalWrite(RedLED, HIGH);
delay(250);
digitalWrite(RedLED, LOW);
delay(250);
}
 
void BlinkYellow()
{
if (LEDStatus=="ON"){
  digitalWrite(YellowLED,LOW);
  LEDStatus="OFF";
  return;
  }
if (LEDStatus=="OFF"){
  digitalWrite(YellowLED,HIGH);
  LEDStatus="ON";
  return;
}
}
