# ES3011 Final Project

## CAD
Includes STL files for the vehicle chassis and wheels.

## src
- config_dump — Prints all configuration variables for the SmartMotor with the address entered into the Arduino IDE Serial Monitor.

- i2c_scanner — Scans for any I²C devices connected to the microcontroller and prints the address of any devices found (useful if you do not know the address of a SmartMotor).

- pid_tuning_demo — Sets both the position and velocity PID gains and then prints the new values to the Serial Monitor.

- position_control_demo — Rotates a SmartMotor 360° in the positive (CCW) direction every 2 seconds and prints the current motor position to the Serial Monitor.

- SMClib — A library containing all of the code necessary to operate the SmartMotors, including a wrapper class (i.e., SmartMotor) that handles all low-level communication between the microcontroller and the SMC.

- velocity_control_demo — Sets the motor velocity to 60 RPM and prints the current motor velocity to the Serial Monitor every 2 seconds.