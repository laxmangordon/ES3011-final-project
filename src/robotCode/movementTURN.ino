#include "movementCode.h"

int turnMovement() {
  static int turnTempVar = 0;

  if (!turnTempVar) {
    targetAngleRight -= 600;
    targetAngleLeft -= 600;
    motorLeft.write_angle(targetAngleLeft);
    motorRight.write_angle(targetAngleRight);
    turnTempVar += 1;
  }

  if ((motorLeft.read_angle() >= (targetAngleLeft - 600)) && (motorRight.read_angle() <= (-targetAngleRight - 600))){
      Serial.print("Left :");
      Serial.println(motorLeft.read_angle());
      Serial.print("Right :");
      Serial.println(motorRight.read_angle());
      return 1;
    }

  return 0;
}