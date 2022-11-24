//#include "motors.h"
#include <PS2X_lib.h>
#include <motor.h>
#include <L298NX2.h>

PS2X ps2x; // create PS2 Controller Class

/******************************************************************
 * set pins connected to PS2 controller:
 *   - 1e column: original 
 *   - 2e colmun: Stef?
 * replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT        13  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

/******************************************************************
 * select modes of PS2 controller:
 *   - pressures = analog reading of push-butttons 
 *   - rumble    = motor rumbling
 * uncomment 1 of the lines for each mode selection
 ******************************************************************/
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

void setupPS2controller()
{
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
  ps2x.readType();
  //  ps2x.read_gamepad(false, 0); // disable vibration of the controller
}
bool PS2control()
{
  // Based on IgorF2's Arduino Bot:https://www.instructables.com/Arduino-Robot-With-PS2-Controller-PlayStation-2-Jo/

  int nJoyL = ps2x.Analog(PSS_LY); // read left stick      
  int nJoyR = ps2x.Analog(PSS_RY); // read right stick             


  if (nJoyL > 127)
  {
    motors.forward();
    int calSpeed1 = abs(255-nJoyL);
    motors.setSpeed(nJoyL);
  }
  
}
