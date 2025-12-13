#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>
#include <smc_gains.h>
#include "movementCode.h"

//----------------------------------------------
#define tuningSet 1

SmartMotor motorRight(0x0B);
SmartMotor motorLeft(0x0A);

float kvLeft = 0;
float kpLeft = .3;
float kiLeft = .3;
float kdLeft = .5;

float kvRight = 0;
float kpRight = .3;
float kiRight = .3;
float kdRight = .5;

//----------------------------------------------

int32_t speedRPMLeft = 100;
int32_t speedRPMRight = -105;

int32_t speedRPMLeftTurn = 100;
int32_t speedRPMRightTurn = 105;

int32_t speedOFF = 0;

float motorLeftPos;
float motorRightPos;
float error;

int32_t targetAngleRight = -1805;
int32_t targetAngleLeft = 1805;

long int currentTime = 0;
long int previousTime = 0;

typedef enum {
  TUNING,
  INITALISE,
  FORWARD,
  TURN,
  REVERSE
} States;


States currentState = TUNING;
void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Wire.begin();

  motorLeft.tune_pos_pid(kpLeft, kiLeft, kdLeft);
  motorRight.tune_pos_pid(kpRight, kiRight, kdRight);
}

void loop() {
  long unsigned int currentTime;
  long unsigned int previousTime;

  float motorLeftPos;
  float motorRightPos;

  uint8_t statusLeft;
  uint8_t statusRight;

  float output;

  /*if (tuningSet) {
    currentState = TUNING;
    Serial.println("Setting state to TUNING");
  }*/

  switch (currentState) {
    case TUNING:
      tuningSetup();
      currentState = INITALISE;
      break;

    case INITALISE:
      /*motorLeft.write_rpm(speedRPMLeft);
      motorRight.write_rpm(speedRPMRight);*/

      if (!initaliseCode()) { currentState = FORWARD; }
      break;

    case FORWARD:
      //Serial.println("FORWARD State");
      if (!forwardMovement()) {currentState = TURN;}
      break;

    case TURN:
      //Serial.println("TURN State");
      if (!turnMovement()) { currentState = REVERSE; }
      break;

    case REVERSE:
      //Serial.println("reVerse State");
      if (!reverseMovement()) {
        Serial.println("Done");
        motorLeft.write_rpm(speedOFF);
        motorRight.write_rpm(speedOFF);
        while (1) {
          NOP;
        }
      }
      break;
  }
}
