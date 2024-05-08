#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(1);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup() {
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void loop() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}
