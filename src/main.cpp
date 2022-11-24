#include <Arduino.h>
#include <PS2_controller.h>
#include <L298NX2.h>

const unsigned int EN_A = 3;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 6;

const unsigned int IN1_B = 7;
const unsigned int IN2_B = 8;
const unsigned int EN_B = 9;

L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

void setSpeed(long motorA,long motorB){
    motors.setSpeedA(motorA);
    motors.setSpeedB(motorB);
}

void setup(){
  Serial.begin(57600);
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it
  setupPS2controller();
}

void loop() {
  PS2control();
}
 
