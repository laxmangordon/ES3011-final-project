#include "movementCode.h"

int tuningSetup() {
  motorLeft.tune_pos_pid(kpLeft, kiLeft, kdLeft);
  motorRight.tune_pos_pid(kpRight, kiRight, kdRight);
  delay(1000);

  Gains pos_gains_left = motorLeft.get_pos_gains();
  Serial.println("Left Motor Position PID Gains: ");
  Serial.println("------------------");
  Serial.print("Kp: ");
  Serial.println(pos_gains_left.kp);
  Serial.print("Ki: ");
  Serial.println(pos_gains_left.ki);
  Serial.print("Kd: ");
  Serial.println(pos_gains_left.kd);
  Serial.println();

  Gains pos_gains_right = motorRight.get_pos_gains();
  Serial.println("Right Motor Position PID Gains: ");
  Serial.println("------------------");
  Serial.print("Kp: ");
  Serial.println(pos_gains_right.kp);
  Serial.print("Ki: ");
  Serial.println(pos_gains_right.ki);
  Serial.print("Kd: ");
  Serial.println(pos_gains_right.kd);
  Serial.println();


  motorLeft.tune_vel_pid(kvLeft, kpLeft, kiLeft, kdLeft);
  motorRight.tune_vel_pid(kvRight, kpRight, kiRight, kdRight);
  delay(1000);

  Gains vel_gains_left = motorLeft.get_vel_gains();
  Serial.println("Left Motor Velocity PID Gains: ");
  Serial.println("------------------");
  Serial.print("Kv: ");
  Serial.println(vel_gains_left.kv);
  Serial.print("Kp: ");
  Serial.println(vel_gains_left.kp);
  Serial.print("Ki: ");
  Serial.println(vel_gains_left.ki);
  Serial.print("Kd: ");
  Serial.println(vel_gains_left.kd);
  Serial.println();

  Gains vel_gains_right = motorRight.get_vel_gains();
  Serial.println("Right Motor Velocity PID Gains: ");
  Serial.println("------------------");
  Serial.print("Kv: ");
  Serial.println(vel_gains_right.kv);
  Serial.print("Kp: ");
  Serial.println(vel_gains_right.kp);
  Serial.print("Ki: ");
  Serial.println(vel_gains_right.ki);
  Serial.print("Kd: ");
  Serial.println(vel_gains_right.kd);
  Serial.println();

  while (1) {
    NOP;
  }
  return 0;
}