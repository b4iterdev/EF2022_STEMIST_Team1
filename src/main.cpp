#include <Arduino.h>
#include <PS2_controller.h>

void setup(){
  Serial.begin(57600);
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it.
  setupPS2controller();
}

void loop() {
  ps2x.read_gamepad(false,0);
  PS2control();
  motorControl();
}
 
