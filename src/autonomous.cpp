#include "intake.hpp"
#include "lemlib/chassis/chassis.hpp"
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
    chassis.setPose(0,0,0);
    loading();
    chassis.moveToPose(0, 10, 55,1000, {true,0,0.5,65,2,1});
    chassis.moveToPose(3,27,34,3000,{true,0,0.5,65,8,1});
    chassis.moveToPoint(21.1,40.7,2000,{true,39,4,1});
    chassis.waitUntil(22.9);
    pros::delay(1500);
    stop();
    chassis.moveToPoint(14.5,28,2000,{false,39,2,1});
    pros::delay(1200);
    chassis.turnToHeading(220.7,10);
    chassis.moveToPose(28,10,180,3000,{true,0,0,80,8,1});
    chassis.moveToPoint(28,34,2000,{false,70,0,1});
    pros::delay(1000);
    score_top();
    pros::delay(4000);
    scraper_toggled();
    chassis.moveToPoint(28,-12.5,1000,{true,60,50,1});
    loading();
    pros::delay(3500);
    chassis.moveToPoint(28,34,2000,{false,70,0,1});
    chassis.waitUntilDone();
    score_top();
    // pros::delay(1700);
    // chassis.moveToPoint(0,0,1000,{false,39,0,1});
    // pros::delay(1000);
    // score_top();
    // chassis.moveToPoint(30,48.2,3000,{true,45,1,1});
}


void second_auton(){
    chassis.setPose(0,0,0);

    // first three blocks
    loading();
    chassis.moveToPose(0, 10, -55,1000, {true,0,0.5,65,2,1});
    chassis.moveToPose(-3,27,-34,3000,{true,0,0.5,65,8,1});
   
    // two middle blocks
    chassis.moveToPoint(-21.3,42,2000,{true,39,4,1});
    chassis.waitUntil(22.9);
    pros::delay(1500);
    stop();


    // moving
    chassis.moveToPoint(-14.5,28,2000,{false,39,2,1});
    pros::delay(1200);

    // scoring
    chassis.turnToHeading(-220.7,10);
    chassis.moveToPose(-35,10,180,3000,{true,0,0,80,8,1});
    chassis.moveToPoint(-35,34,2000,{false,70,0,1});
    pros::delay(1000);
    score_top();
    pros::delay(4000);
    scraper_toggled();
    chassis.moveToPoint(-33.5,-10,1000,{true,50,40,1});
    loading();
    pros::delay(1700); 
}

void move(){
    chassis.moveToPoint(1,1,1000,{true,50,40,1});
}

void shit_auton(){
    // add code here
}