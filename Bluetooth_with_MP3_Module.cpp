// PROGRAMMED BY: Mudassir Nadeem

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

static const uint8_t PIN_MP3_TX = 8; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 9; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;

DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
  softwareSerial.begin(9600);
  player.begin(softwareSerial);
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led4 , OUTPUT);
  pinMode(led5 , OUTPUT);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
char terminalRead;

void loop() {
  if (Serial.available() > 0) {
    terminalRead = Serial.read();
    delay(30);


    if (terminalRead == 'a') {
      player.volume(25);
      player.play(0001);
      delay(2000);
      digitalWrite(led1 , LOW);

      // Play the first MP3 file on the SD card

    }

    if (terminalRead == 'b') {
      digitalWrite(led1 , HIGH);
      player.pause();
      delay(2000);
    }
    if (terminalRead == 'c') {
      digitalWrite(led2 , HIGH);
      player.volume(25);
      // Play the first MP3 file on the SD card
      player.play(0002);
      delay(2000);
    }
    if (terminalRead == 'd') {
      digitalWrite(led2 , LOW);
      player.pause();
      delay(2000);
    }
    if (terminalRead == 'e') {
      digitalWrite(led3 , HIGH);
      player.volume(25);
      // Play the first MP3 file on the SD card
      player.play(0003);
      delay(2000);
    }
    if (terminalRead == 'f') {
      digitalWrite(led3 , LOW);
      player.pause();
      delay(2000);
    }
    if (terminalRead == 'g') {
      digitalWrite(led4 , HIGH);
      player.volume(25);
      // Play the first MP3 file on the SD card
      player.play(0004);
      delay(2000);
    }
    if (terminalRead == 'h') {
      digitalWrite(led4 , LOW);
      player.pause();
      delay(2000);
    }
    if (terminalRead == 'i') {
      digitalWrite(led5 , HIGH);

    }

    if (terminalRead == 'j') {
      digitalWrite(led5 , LOW);

    }
    if (terminalRead == 'k') {
      player.play(0001);
      delay(5000);
      player.play(0002);
      delay(5000);
      player.play(0003);
      delay(5000);
      player.play(0004);

      delay(5000);
    }
    if (terminalRead == 'l') {
      player.pause();
      delay(2000);
    }


  }
}
