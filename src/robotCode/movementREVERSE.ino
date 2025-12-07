#include "movementCode.h"

int reverseMovement() {
  static int reverseTempVar = 0;

  if (!reverseTempVar) {
    targetAngleLeft *= 2;
    targetAngleRight *= 2;
    motorLeft.write_angle(targetAngleLeft);
    motorRight.write_angle(targetAngleRight);
    /*Serial.print("set the target angle to: ");
    Serial.println(targetAngle);*/

    reverseTempVar += 1;
  }

  Serial.print("Left motor angle");
  Serial.println(motorLeft.read_angle());
  Serial.print("Right motor angle");
  Serial.println(motorRight.read_angle());

  if ((motorLeft.read_angle() == targetAngleLeft) && (motorRight.read_angle() == targetAngleRight)) {
    return 0;
  }

  return 1;
}