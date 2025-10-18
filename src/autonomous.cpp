#include "main.h"


const int DRIVE_SPEED = 127;
const int TURN_SPEED = 100;
const int SWING_SPEED = 110;


void tuning_auton(){
    chassis.moveToPose(10,0,20,3000);
}
