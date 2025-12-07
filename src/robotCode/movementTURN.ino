#include "movementCode.h"

int turnMovement() {
  static int turnTempVar = 0;

  if (!turnTempVar) {
    motorLeft.write_angle(targetAngle - 600);
    motorRight.write_angle(-targetAngle - 600);
    turnTempVar += 1;
  }

  if ((motorLeft.read_angle() != (targetAngle - 252)) && (motorRight.read_angle() != (targetAngle - 252))){
      Serial.println(motorLeft.read_angle());
      Serial.println(motorRight.read_angle());
      return 1;
    }

  return 0;
}