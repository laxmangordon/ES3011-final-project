#include "movementCode.h"

int forwardMovement() {
  currentTime = millis();

  motorLeft.write_angle(-targetAngle);  //fix these
  motorRight.write_angle(targetAngle);

  if ((currentTime - previousTime) >= samplingTime) {
    motorLeftPos = (float)motorLeft.read_angle();
    motorRightPos = (float)motorRight.read_angle();

    error = motorLeftPos - motorRightPos;
    totalError += error;
    deltaError = error - lastError;

    output = (Kp * error) + ((Kd / samplingTime) * deltaError) + ((Ki * samplingTime) * totalError);

    motorLeft.write_rpm(speedRPM - output);
    motorRight.write_rpm(speedRPM + output);

    lastError = error;
    previousTime = currentTime;
  }

  return 0;
}