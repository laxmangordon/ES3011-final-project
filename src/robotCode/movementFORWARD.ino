#include "movementCode.h"

int forwardMovement() {
  static int tempVar = 0;

  currentTime = millis();

  if (!tempVar) {
    motorLeft.write_angle(0);
    motorRight.write_angle(0);
    Serial.print("set the target angle to: ");
    Serial.println(targetAngle);

    while (motorLeft.read_angle() != 0){
      Serial.println(motorLeft.read_angle());
    }
    motorLeft.write_angle(-targetAngle);
    motorRight.write_angle(targetAngle);
    Serial.print("set the target angle to: ");
    Serial.println(targetAngle);

    tempVar += 1;
  }

  if ((currentTime - previousTime) >= samplingTime) {
    motorLeftPos = (float)motorLeft.read_angle();
    motorRightPos = (float)motorRight.read_angle();

    Serial.print("left motor angle position: ");
    Serial.println(motorLeftPos);
    Serial.print("right motor angle position: ");
    Serial.println(motorRightPos);

    error = motorRightPos - motorLeftPos;
    Serial.print("Error: ");
    Serial.println(error);
    totalError += error;
    Serial.print("Total Error: ");
    Serial.println(totalError);
    deltaError = error - lastError;
    Serial.print("Delta Error: ");
    Serial.println(deltaError);

    output = (Kp * error) + ((Kd / samplingTime) * deltaError) + ((Ki * samplingTime) * totalError);
    Serial.print("Output: ");
    Serial.println(output);

    motorLeft.write_rpm(speedRPM - output);
    motorRight.write_rpm(speedRPM + output);

    lastError = error;
    previousTime = currentTime;
  }

  if (motorRight.read_angle() >= targetAngle) {
    return 0;
  }

  return 1;
}