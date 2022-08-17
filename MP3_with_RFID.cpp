// PROGRAMMED BY: Mudassir Nadeem

#include <Arduino.h> 
#include <SPI.h>
#include <MFRC522.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX 
int L5 = 5; //Red Light
int L4 = 4; //Yellow Light
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini

  player.begin(softwareSerial); // DFPlayer Mini
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "26 2A F2 29") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    digitalWrite(L5, LOW);
    digitalWrite(L4, HIGH);                        //FIRST IF
    delay(750);
    digitalWrite(L4, LOW);
    // Set volume to maximum (0 to 30).
    player.volume(25);
    // Play the first MP3 file on the SD card
    player.play(0001);
    delay(2000);
    Serial.println();
    delay(3000);
  }

  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "11 6C EF 29") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    digitalWrite(L5, LOW);
    digitalWrite(L4, HIGH);
    delay(750);                                 //2ND IF
    digitalWrite(L4, LOW);
    
    // Set volume to maximum (0 to 30).
    player.volume(25);
    // Play the first MP3 file on the SD card
    player.play(0002);
    delay(2000);
    Serial.println();
    delay(3000);
    Serial.println();
    delay(3000);
  }
 

  if (content.substring(1) == "0B 4B 4F 00") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    digitalWrite(L5, LOW);
    digitalWrite(L4, HIGH);
    delay(750);                               //3RD IF
    digitalWrite(L4, LOW);
    
    // Set volume to maximum (0 to 30).
    player.volume(25);
    // Play the first MP3 file on the SD card
    player.play(0003);
    delay(2000);
    Serial.println();
    delay(3000);
    Serial.println();
    delay(3000);
  }
 


  if (content.substring(1) == "F3 5F D8 55") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    digitalWrite(L5, LOW);
    digitalWrite(L4, HIGH);
    delay(750);                               //4TH IF
    digitalWrite(L4, LOW);
    
    // Set volume to maximum (0 to 30).
    player.volume(25);
    // Play the first MP3 file on the SD card
    player.play(0004);
    delay(2000);
    Serial.println();
    delay(3000);
    Serial.println();
    delay(3000);
  }
 


  if (content.substring(1) == "02 4B A4 1B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    digitalWrite(L4, LOW);
    digitalWrite(L5, HIGH);
    delay(750);                               //5TH IF
    digitalWrite(L5, LOW);
    
    
    player.pause();
    delay(2000);
    Serial.println();
    delay(3000);
    Serial.println();
    delay(3000);
  }
 
 else   {
    Serial.println(" Access denied");
    Serial.println(" Connected to DFRobotDFPlayerMini player");
    delay(3000);
  }




  
} 
