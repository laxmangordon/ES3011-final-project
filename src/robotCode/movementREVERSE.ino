#include "movementCode.h"

int reverseMovement() {
  static int reverseTempVar = 0;

  if (!reverseTempVar) {
    motorLeft.write_angle(0);
    motorRight.write_angle(0);
    Serial.print("set the target angle to: ");
    Serial.println(targetAngle);

    while ((motorLeft.read_angle() != 0) && (motorRight.read_angle() != 0)) {
      Serial.println(motorLeft.read_angle());
      Serial.println(motorRight.read_angle());
    }
    motorLeft.write_angle((targetAngle - 252) - targetAngle);
    motorRight.write_angle((-targetAngle - 252) + targetAngle);
    Serial.print("homing");

    reverseTempVar += 1;
  }

  Serial.print("Left motor angle");
  Serial.println(motorLeft.read_angle());
  Serial.print("Right motor angle");
  Serial.println(motorRight.read_angle());

  if ((motorLeft.read_angle() == ((targetAngle - 252) - targetAngle)) && (motorRight.read_angle() == ((-targetAngle - 252) + targetAngle))) {
    return 0;
  }

  return 1;
}