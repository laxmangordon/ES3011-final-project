#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>
#include <smc_gains.h>

//----------------------------------------------
#define tuningSet 0

float kvLeft = 1.0;
float kpLeft = 0.65;
float kiLeft = 0.060;
float kdLeft = 0.065;

float kvRight = 1.0;
float kpRight = 0.65;
float kiRight = 0.060;
float kdRight = 0.065;
//----------------------------------------------

#define speedRPM 60

void setup() {
  Serial.begin(9600);
  while (!Serial);

  SmartMotor motorLeft(0x0A);
  SmartMotor motorRight(0x0B);
  Wire.begin();

  if (tuningSet) {

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
      ;;
    }
  }

  uint8_t statusLeft = motorLeft.write_rpm(speedRPM);
  uint8_t statusRight = motorRight.write_rpm(speedRPM);
}

void loop() {

  

}
