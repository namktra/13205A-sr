#include "main.h"
#include "pneumatics.hpp"
#include "pros/rtos.h"
#include "subsystems.hpp"

const int DRIVE_SPEED = 127;
const int TURN_SPEED = 100;
const int SWING_SPEED = 110;


void tuning_auton(){
    chassis.setPose(0,0,0);
    chassis.moveToPose(0,40,0,3300);
    pros::c::delay(1000);
    chassis.moveToPose(0,0,0,5000,{false,0,0,80,0,0.8});
}

void first_auton(){
    scraper_toggled();
    chassis.setPose(0,0,0);
    loading();
    chassis.moveToPose(2,24.2,8,5000,{true,0,0.5,40,25,0.8});  
    // in the curly braces it goes {foward, horiziontal drift, another value, MAX SPEED, MIN SPEED, another value}
    // tweak max and min speed for accurate auton i would suggest having a low min speed for now like 0-10
    loading();
}

void template_function(){
    // add code here
}

void shit_auton(){
    // add code here
}