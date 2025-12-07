#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>
#include <smc_gains.h>
#include "movementCode.h"

//----------------------------------------------
#define tuningSet 0

float kvLeft = 1.0;
float kpLeft = 0.65;
float kiLeft = 0.060;
float kdLeft = 0.065;

float kvRight = 1.0;
float kpRight = 0.65;
float kiRight = 0.060;
float kdRight = 0.065;

//----------------------------------------------

#define speedRPM 60

float motorLeftPos;
float motorRightPos;
float error;

int32_t targetAngleRight = -1805;
int32_t targetAngleLeft = 1805;

typedef enum {
  TUNING,
  INITALISE,
  FORWARD,
  TURN,
  REVERSE
} States;


States currentState = INITALISE;
void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Wire.begin();
}

void loop() {
  long unsigned int currentTime;
  long unsigned int previousTime;

  float motorLeftPos;
  float motorRightPos;

  int32_t targetAngle;

  uint8_t statusLeft;
  uint8_t statusRight;

  float output;

  if (tuningSet) {
    currentState = TUNING;
    Serial.println("Setting state to TUNING");
  }

  switch (currentState) {
    case TUNING:
      tuningSetup();
      break;

    case INITALISE:
      statusLeft = motorLeft.write_rpm(speedRPM);
      statusRight = motorRight.write_rpm(speedRPM);

      targetAngle = 1805;

      if (!initaliseCode()) {currentState = FORWARD;}
      break;

    case FORWARD:
      Serial.print("FORWARD State");
      if (!forwardMovement()) {currentState = TURN;}
      break;

    case TURN:
      Serial.print("TURN State");
      if (!turnMovement()){currentState = REVERSE;}
        break;

    case REVERSE:
      Serial.println("reVerse State");
      if (!reverseMovement()) {Serial.print("Done");}
      break;
  }
}
