#include "movementCode.h"

int turnMovement() {
  static int turnTempVar = 0;
  currentTime = millis();

  if (!turnTempVar) {
    motorLeft.write_rpm(speedRPMLeftTurn);
    motorRight.write_rpm(speedRPMRightTurn);

    turnTempVar += 1;
  }

  // Serial.print("Right Motor: ");
  //Serial.println(motorRight.read_angle());
  // Serial.print("Left Motor: ");
  //Serial.println(motorLeft.read_angle());

  if ((currentTime - previousTime) > 6000) {
    previousTime = currentTime;
    return 0;
  }

  return 1;
/*
  if (!turnTempVar) {
    targetAngleRight -= motorLeft.read_angle() + 514;
    targetAngleLeft -= motorRight.read_angle() + 514;
    motorLeft.write_angle(targetAngleLeft);
    motorRight.write_angle(targetAngleRight);
    turnTempVar += 1;
  }

  if ((motorLeft.read_angle() >= targetAngleLeft) && (motorRight.read_angle() >= targetAngleRight)){
      Serial.print("Left :");
      Serial.println(motorLeft.read_angle());
      Serial.print("Right :");
      Serial.println(motorRight.read_angle());
      return 0;
    }

  return 1;*/
}