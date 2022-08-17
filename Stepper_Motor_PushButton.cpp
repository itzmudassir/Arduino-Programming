// PROGRAMMED BY: Mudassir Nadeem

#include <Stepper.h>
const int buttonPin =  12;
int  initial    = 0;
int oldstate    = 0;
int buttonstate = 0;

// Define Constants
 
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables
 
// Number of Steps Required
int StepsRequired;
 
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
 
Stepper steppermotor(STEPS_PER_REV, 9, 11, 10, 6);
void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonstate = digitalRead(buttonPin);
  if (buttonstate == HIGH) {
          
    buttonstate = digitalRead(buttonPin);
    if (buttonstate == LOW) {
       StepsRequired  =  - STEPS_PER_OUT_REV / 2;   
  steppermotor.setSpeed(700);  
  steppermotor.step(StepsRequired);
  
    }
  } else {
    
    
  }
  

}
