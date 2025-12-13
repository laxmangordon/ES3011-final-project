#include "movementCode.h"

int reverseMovement() {
  static int reverseTempVar = 0;
  currentTime = millis();

  if (!reverseTempVar) {
    motorLeft.write_rpm(speedRPMLeft);
    motorRight.write_rpm(speedRPMRight);

    reverseTempVar += 1;
  }

  // Serial.print("Right Motor: ");
  //Serial.println(motorRight.read_angle());
  // Serial.print("Left Motor: ");
  //Serial.println(motorLeft.read_angle());

  if ((currentTime - previousTime) > 5000) {
    previousTime = currentTime;
    return 0;
  }

  return 1;
/*
  if (!reverseTempVar) {
    targetAngleLeft += 1805;
    targetAngleRight -= 1805;
    motorLeft.write_angle(targetAngleLeft);
    motorRight.write_angle(targetAngleRight);
    /*Serial.print("set the target angle to: ");
    Serial.println(targetAngle);

    reverseTempVar += 1;
  }

  Serial.print("Left motor angle: ");
  Serial.println(motorLeft.read_angle());
  Serial.print("Right motor angle: ");
  Serial.println(motorRight.read_angle());

  if ((motorLeft.read_angle() >= targetAngleLeft) && (motorRight.read_angle() <= targetAngleRight)) {
    return 0;
  }

  return 1;*/
}