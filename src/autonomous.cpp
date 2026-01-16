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
    scraper.set_value(false);
}

void right_auton(){
    chassis.setPose(0,0,0);

    
    loading();
    // chassis.moveToPoint(6, 22, 2000,{true,60,45,1});
    // chassis.moveToPoint(12, 30,2000,{true,60,55,1});
    // chassis.moveToPose(21.1,40.7,67,2000,{true,55,4,1});

    chassis.moveToPoint(2.7, 10.6,1750, {true,58,30.5,1});
    chassis.moveToPoint(5.6,33,3000,{true,50,40,1});
    chassis.moveToPose(26.8,42,72,7500,{true,0,0,45,0,1});
    pros::delay(2000);
    chassis.moveToPoint(14.5,28,2000,{false,60,2,1});
    pros::delay(1200);
    chassis.turnToHeading(220.7,10);
    chassis.moveToPose(29.3,9.4,180,3000,{true,0,0,80,8,1});
    chassis.moveToPoint(29.3,34,2000,{false,70,0,1});
    pros::delay(1000);
    score_top();
    pros::delay(2250);
    scraper_toggled();
    chassis.moveToPoint(29.3,-16.5,1500,{true,50,50,1});
    loading();
    pros::delay(2000);
    chassis.moveToPoint(29.3,34,1000,{false,70,0,1});
    chassis.waitUntilDone();
    score_top();
}


void left_auton(){
    chassis.setPose(0,0,0);
    loading();
    chassis.moveToPoint(-2.7, 10.6,1750, {true,70,30.5,1});
    chassis.moveToPoint(-5.6,33.2,3000,{true,60,40,1});
    chassis.moveToPose(-26.2,45.8,-75,7500,{true,0,0,38,0,1});
    pros::delay(2000);
    chassis.moveToPoint(-14.5,28,2000,{false,60,2,1});
    pros::delay(1200);
    chassis.turnToHeading(40.7,10);
    chassis.moveToPose(-35,9.4,180,3000,{true,0,0,80,8,1});
    chassis.moveToPoint(-35,32,2000,{false,70,0,1});
    pros::delay(1000);
    score_top();
    pros::delay(2250);
    scraper_toggled();
    chassis.moveToPoint(-35,-15,1500,{true,60,50,1});
    loading();
    pros::delay(1600);
    chassis.moveToPoint(-35,32,1000,{false,70,0,1});
    chassis.waitUntilDone();
    score_top();


}

void move(){
    chassis.moveToPoint(1,1,1000,{true,50,40,1});
}

void skills_auton(){
    chassis.setPose(0,0,0);
    score_top();
    chassis.moveToPoint(0, -5,2000,{false,50,0,1});
    chassis.moveToPoint(0, 17, 1000,{true,100,0,1});
}

void new_skills_auto(){
    // first match loader
     pros::delay(500);
    chassis.moveToPoint(0, 41.5, 4500,{true,70,1});
    chassis.turnToHeading(90, 1500);
    scraper_toggled();
    loading();
    chassis.moveToPoint(25, 44.5, 2000,{true,55,0,1});
    pros::delay(3500);
    chassis.moveToPoint(23, 44.5, 2000,{true,55,0,1});
    pros::delay(3500);
    chassis.moveToPoint(0, 44.5, 4500,{false,70,1});
    scraper_toggled();

    // movement to second loader
    chassis.moveToPoint(-15, 61, 1500,{false,70,1});
    pros::delay(1500);
    chassis.turnToHeading(90, 1500);
    chassis.moveToPoint(-88, 61, 1500,{false,100,1});
    pros::delay(1500);
    chassis.moveToPoint(-88, 50, 1500,{false,70,0});
    pros::delay(1500);
    chassis.turnToHeading(270, 1500);
    pros::delay(1500);
    chassis.setPose(0,0,270);
    
    // scoring first 6 blocks
    chassis.moveToPoint(18, 0, 1500,{false,70,1});
    pros::delay(750);
    score_top();

    // intaking second loader
    scraper_toggled();
    pros::delay(2000);
    loading();
    chassis.moveToPoint(-20, 0, 2000,{true,55,5});
    pros::delay(2500);
    
    // scoring second set of 6 blocks
    chassis.moveToPoint(18, 0, 1500,{false,64,5});
    chassis.waitUntilDone();
    score_top();
    scraper_toggled();
    pros::delay(2000);
    

    // third goal 
    pros::delay(750);
    loading();
    pros::delay(750);
    chassis.moveToPoint(-5, 0, 1500,{true,64,0});
    pros::delay(750);
    chassis.turnToHeading(180, 750);
    pros::delay(750);
    chassis.moveToPoint(-5, -98.5, 5000,{true,90,0});
    pros::delay(500);
    chassis.turnToHeading(270, 500);
    pros::delay(500);
    scraper_toggled();
    pros::delay(500);      
      chassis.moveToPoint(-24, -98.5, 5000,{true,90,0});
    pros::delay(500);
    chassis.moveToPoint(-12, -98.5, 5000,{false,90,0});
    chassis.waitUntilDone();
    score_top();
    // pros::delay(500);
    // chassis.moveToPoint(18, -93.5, 2000,{true,90,0});
    // pros::delay(500);
    // pros::delay(1000);
    // loading();
    // chassis.moveToPoint(-20, 0, 3000,{true,105,0});
    // pros::delay(1250);

    // // move to fourth
    // chassis.moveToPoint(0, 0, 1250,{false,70,1});
    // chassis.moveToPoint(27, -15, 1250,{false,70,1});
    // pros::delay(500);
    // chassis.turnToHeading(270, 500);
    // chassis.moveToPoint(95, -15, 2000,{false,100,1});
    // chassis.moveToPoint(104, -4, 2000,{false,100,1});
    // chassis.turnToHeading(90, 500);
    // chassis.setPose(0,0,90);

    // // scoring 3rd set of blocks
    // chassis.moveToPoint(-17, 0, 2000,{false,70,1});
    // chassis.waitUntilDone();
    // score_top();
    // pros::delay(2500);
    // scraper_toggled();
    // loading();
    // pros::delay(750);

    // // intaking 4th set
    // chassis.moveToPoint(20, 0, 2000,{true,70,1});
    // pros::delay(2000);
    
    // // scoring 4th set
    // chassis.moveToPoint(-17, 0, 2000,{false,70,1});
    // chassis.waitUntilDone();
    // score_top();
    // pros::delay(2500);

    // chassis.moveToPoint(-85, 45, 1500,{false,70,1});
    // chassis.moveToPoint(0, 46.5, 4500,{false,55,1});
    // scraper_toggled();
    // chassis.turnToHeading(180, 1500);
    // chassis.moveToPoint(0, -45, 4500,{true,55,1});
    // scraper_toggled();
    // chassis.turnToHeading(90, 1500);
    // chassis.moveToPoint(25, -49.3, 4500,{true,55,1});
    // chassis.moveToPoint(5, -49.3, 4500,{true,55,1}); 
    // chassis.turnToHeading(0, 1500);
    // chassis.moveToPoint(15.2, -14,3000,{true,50,40,1});
    // chassis.turnToHeading(0, 1000);
    // chassis.moveToPoint(15.2, 14,1500,{true,100,0,1});

    
}



void four_three_left_auton(){
    chassis.setPose(0,0,0);
    loading();
    //pick up balls
    chassis.moveToPoint(-5, 20,2050, {true,50,30.5,1});
    pros::delay(2000);
    //turn to goal
    chassis.turnToHeading(225, 1500);
    chassis.moveToPoint(-4, 36,2050, {false,50,30.5,1});
}