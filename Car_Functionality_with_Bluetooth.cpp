// PROGRAMMED BY: Mudassir Nadeem

#include <Arduino.h>

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

int IN1 = 10; 
int IN2 = 11;
int IN3 = 4;
int IN4 = 7;
int en1 = 5;
int en2 = 6;
int Speed = 200;

DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
  softwareSerial.begin(9600);
  player.begin(softwareSerial);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}
char terminalRead;

void loop() {
  if (Serial.available() > 0) {
    terminalRead = Serial.read();
    delay(30);


    if (terminalRead == 'a') {
      forward();
      player.volume(25);
      player.play(0004);
      delay(2000);
      

      // Play the first MP3 file on the SD card

    }

    if (terminalRead == 'b') {
      stops();
      player.pause();
      
    }
    if (terminalRead == 'c') {
      reverse();
      player.volume(25);
      // Play the first MP3 file on the SD card
      player.play(0005);
      delay(2000);
    }
    if (terminalRead == 'd') {
      stops();
      player.pause();
     
    }
    if (terminalRead == 'e') {
      right();
      player.volume(25);
      // Play the first MP3 file on the SD card
      player.play(0003);
      delay(2000);
    }
    if (terminalRead == 'f') {
      stops();
      player.pause();
    }
    if (terminalRead == 'g') {
      left();
      player.volume(25);
      // Play the first MP3 file on the SD card
      player.play(0002);
      delay(2000);
    }
    if (terminalRead == 'h') {
      stops();
      player.pause();
    }
   
  }
}

void forward(){
  analogWrite(en1, Speed);
  analogWrite(en2, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
}

void reverse(){
  analogWrite(en1, Speed);
  analogWrite(en2, Speed);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
}

void right(){
  analogWrite(en1, Speed);
  analogWrite(en2, Speed);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
}

void left(){
  analogWrite(en1, Speed);
  analogWrite(en2, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, HIGH);
}

void stops(){
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
}
