/*
 *Titanfall Nuke Eject Keyboard Emulation
 *System will print a sequence of X + E + E + E keys when the button is pressed
 *delays were implemented to prevent overloading game input
 *
 *Future plans are to implement a red saftey toggle switche for titan core ability
 *
 *Austin Esser
 *February 18th 2016
*/

//need arduino keyboard library for interfacing 
//(only built into micro, due, and leonardo. I'm using a micro)
#include "Keyboard.h"

const int ejectButton = 2; // set pin number for the eject button
const int coreButton = 3; // set pin number for core activator toggle switch
int buttonLast; // activate titan core with flip of toggle switch (on to off or off to on)

void setup() { 
  pinMode(ejectButton, INPUT);
  pinMode(coreButton, INPUT);
  Serial.begin(9600);
  //initialize keyboard
  Keyboard.begin();
}

void loop() {
  ejectPress();
  corePress();
}

//big red button function
void ejectPress(){
  // use this pushbutton to control the keyboard:
  if (digitalRead(ejectButton) == HIGH) {
    Keyboard.write('x');
    delay(1); //delay to ensure each emulated key stroke is registered
    Keyboard.write('e');
    delay(1); 
    Keyboard.write('e');
    delay(1); 
    Keyboard.write('e');
    delay(150); 
  }
  else {
    //wait
    //delay for stability
    delay(1);
  }
}

//toggle titan ability with toggle switch
void corePress() {
  int buttonState = digitalRead(coreButton);
  if (buttonState == buttonLast) {
    //do nothing
    delay(1);
  }
  //implement a switch routine that activates for each toggle change
  if (buttonState != buttonLast) {
    Keyboard.write('v');
    delay(1);
  }
  buttonLast = buttonState;
}
