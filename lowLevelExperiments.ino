#include <stdio.h>

/*
 * Arduino has its own names for these registers, but I make my own
 * as an exercise in looking up register addresses.
 * 
 */
uint8_t * myPINB = (uint8_t *)0x23;
uint8_t * myDDRB = (uint8_t *)0x24;
uint8_t * myPORTB = (uint8_t *)0x25;

void setup(){
  *myDDRB |= (2 << 4); //pinMode set to OUTPUT for 13(B5), INPUT for 12(B4)
//  Serial.begin(9600);
}

//In this example, pinB4(12 on the Uno) is hooked up to a button and is normally pulled down.

void loop(){
  uint8_t pinB4 = *myPINB & (1 << 4); //Check if pin B4 is set
  if(pinB4){    
    *myPORTB |= (1 << 5);
  }else{
    *myPORTB &= ~(1 << 5);
  }
  delay(10); //Delay is used to make the simulation smoother.
}
