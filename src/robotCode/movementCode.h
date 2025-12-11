#ifndef movement_CODE_H
#define movement_CODE_H

#define NOP __asm("nop");

int tuningSetup();
int initaliseCode();
int forwardMovement();
int turnMovement();
int reverseMovement();

#endif