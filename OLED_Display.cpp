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

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  

  


}

void loop() {
  stops();
  
}



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
