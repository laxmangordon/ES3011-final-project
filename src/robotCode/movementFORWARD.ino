#include "movementCode.h"

int forwardMovement() {
  static int forwardTempVar = 0;

  if (!forwardTempVar) {
    motorLeft.write_angle(0);
    motorRight.write_angle(0);
    /*Serial.print("set the target angle to: ");
    Serial.println(targetAngle);*/

    while ((motorLeft.read_angle() != 0) && (motorRight.read_angle() != 0)){
      Serial.println(motorLeft.read_angle());
      Serial.println(motorRight.read_angle());
    }
    motorLeft.write_angle(targetAngleLeft);
    motorRight.write_angle(targetAngleRight);
    /*Serial.print("set the target angle to: ");
    Serial.println(targetAngle);*/

    forwardTempVar += 1;
  }

  Serial.print("Left motor angle");
  Serial.println(motorLeft.read_angle());
  Serial.print("Right motor angle");
  Serial.println(motorRight.read_angle());

  if ((motorLeft.read_angle() >= targetAngleLeft) && (motorRight.read_angle() <= targetAngleRight)) {
    return 0;
  }

  return 1;
}