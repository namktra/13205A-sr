#include "distance.hpp"
#include "intake.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pneumatics.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "subsystems.hpp"

const int DRIVE_SPEED = 127;
const int TURN_SPEED = 100;
const int SWING_SPEED = 110;


void lateral_tuning(){
    chassis.setPose(0,0,0);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    chassis.moveToPoint(0,60,3000,{true,40,0,1});
    pros::delay(5000);
    chassis.turnToHeading(180,1000);
    pros::delay(800);
    chassis.moveToPoint(0,0,3000,{true,40,0,1});
    pros::delay(1200);
    ;
    pros::delay(5000);
}
void tuning_auton(){
    chassis.setPose(0,0,0);
    scraper.set_value(false);
    pros::delay(3000);
    scraper.set_value(true);
    pros::delay(1000);
}

void right_auton(){
    chassis.setPose(0,0,0);

    
    loading();
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
     pros::delay(500);
    chassis.moveToPoint(29.3,-16.5,1500,{true,50,50,1});
    loading();
    pros::delay(1600);
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



void four_three_left_auton(){
    chassis.setPose(0,0,0);
    loading();
    chassis.moveToPoint(-2.7, 10.6,1750, {true,70,30.5,1});
    chassis.moveToPoint(-5.6,33.2,3000,{true,60,40,1});
    chassis.moveToPose(-26.2,45.8,-75,7500,{true,0,0,38,0,1});
    pros::delay(2000);
    chassis.moveToPoint(-14.5,28,2000,{false,60,2,1});
    pros::delay(400);
    chassis.turnToHeading(90, 900);
    pros::delay(900);
    ReAlign(4);
    pros::delay(500);
    chassis.turnToHeading(225, 900);
    pros::delay(500);
    chassis.moveToPoint(-12,-10,2000,{false,40,1,3});
    pros::delay(200);
    enabled_mid = true;
    score_top();
    pros::delay(1000);
    loading();
    enabled_mid = false;
    chassis.moveToPoint(-46.757,-45.895,2000,{true,70,0,3});
    pros::delay(500);
    chassis.turnToHeading(180, 800);
    scraper_toggled();
    pros::delay(400);
    ReAlign(4);
    pros::delay(400);
    chassis.moveToPoint(currX,-66,2000,{true,70,0,3});
    pros::delay(100);
    ReAlign(4);
    pros::delay(2000);
    chassis.moveToPoint(currX,-23,1400,{false,70,0,3});
    chassis.waitUntilDone();
    score_top();
    pros::delay(5000);









    
        
        
        
        
        
        
        
        
        
        

    
}

void distance_skills(){
    

    enabled_mid = false;
    //change speed values to tune//
    chassis.setPose(0,0,90);
    pros::delay(500);
    ReAlign(4);
    pros::delay(500);
    chassis.moveToPoint(36, currY, 2500,{.forwards = true,.maxSpeed = 105,.minSpeed = 55,.earlyExitRange = 5});
    chassis.moveToPoint(48.7, currY, 500,{true,55,0,1});
    pros::delay(200);
    ReAlign(1);
    pros::delay(250);
    chassis.turnToHeading(180, 1500);
    scraper_toggled();
    pros::delay(750);

    // //first matchload//

    chassis.moveToPoint(48.7,-70, 1500,{true,60,0,1});
    loading();
    pros::delay(1500);
    chassis.moveToPoint(currX,-50, 1500,{false,60,0,1});
    pros::delay(1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1500);
    scraper_toggled(); 
    chassis.waitUntilDone();

    chassis.moveToPoint(70,-33, 2000,{true,50,0,1});
    pros::delay(1200);
    chassis.turnToHeading(0, 1500);
    pros::delay(500);
    ReAlign(1);
    pros::delay(750);
    
    // // // moving to other side//
    chassis.moveToPoint(currX+2.5,12, 2500,{.forwards = true,.maxSpeed = 105,.minSpeed = 55, .earlyExitRange = 5});
    chassis.moveToPoint(currX+2.5,28, 700,{true,55,0,1});
    pros::delay(800);
    chassis.moveToPoint(49.3,48, 1500,{true,60,0,1});
    pros::delay(850);
    chassis.turnToHeading(270, 1500);
    pros::delay(600);
    ReAlign(2);
    pros::delay(250);
    chassis.turnToHeading(0, 1000);
    pros::delay(400);
    ReAlign(2);
    pros::delay(700);
  


    // // //at 2nd goal//
    
    chassis.moveToPoint(49,25, 1500,{false,60,0,1});
    chassis.waitUntilDone();
    score_top();
    ReAlign(2);
    scraper_toggled();
    pros::delay(2000);
    loading();
    chassis.moveToPoint(currX,70, 1500,{true,60,0,1});
    pros::delay(2500);
    chassis.moveToPoint(currX,25,1500,{false,60,0,1});
    chassis.waitUntilDone();
    score_top();
    pros::delay(2250);
    
    // //move to third matchload//
    
    // // DELETE THIS LATER 
    // chassis.setPose(0,0,270);
    // ReAlign(2);
    // // DELETE THIS LATER

    chassis.moveToPoint(currX,45, 1500,{true,60,0,1});
    pros::delay(500);
    chassis.turnToHeading(270, 1500);
    pros::delay(600);
    ReAlign(2);
    pros::delay(500);
    chassis.moveToPoint(-42,currY, 1250,{.forwards = true,.maxSpeed = 115,.minSpeed = 45, .earlyExitRange = 5});
    chassis.moveToPoint(-55,currY, 1500,{.forwards = true,.maxSpeed = 57,.minSpeed = 1, .earlyExitRange = 0});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1100);
    pros::delay(600);
    ReAlign(3);
    pros::delay(1200);
    
    //third matchload//
    loading();
    chassis.moveToPoint(currX,66.5, 1500,{true,60,0,1});
    pros::delay(2500);
    chassis.moveToPoint(currX,52, 1500,{false,60,0,1});
    pros::delay(1500);
    chassis.turnToHeading(180, 1500);
    chassis.waitUntilDone();
    scraper_toggled();
    pros::delay(1000);

    //moving to fourth matchload//
    
    chassis.moveToPoint(-71, 35, 2300,{true,50,0,1});
    pros::delay(500);
    chassis.turnToHeading(180,800);
    pros::delay(1050);
    ReAlign(3);
    pros::delay(700);
    chassis.moveToPoint(currX-1,-30, 2500,{true,80,0,1},false);
    ReAlign(4);

    pros::delay(1000);
    chassis.moveToPoint(-48.5,-47, 1000,{true,70,0,1});
    pros::delay(250);
    chassis.turnToHeading(90,500);
    pros::delay(250);
    ReAlign(4);
    pros::delay(1050);
    chassis.turnToHeading(180,1000);
    pros::delay(100);
    ReAlign(4);
    pros::delay(600);
    chassis.moveToPoint(currX,-23,1250,{false,75,0,1});
    chassis.waitUntilDone();
    score_top();
    chassis.setPose(-48,-27,180);
    pros::delay(1000);
    scraper_toggled();
    pros::delay(1000);
    loading();
    chassis.moveToPoint(-48,-70,1500,{true,60,0,1});
    pros::delay(2000);
    chassis.moveToPoint(-48,-27,2000,{false,80,0,1});
    chassis.waitUntilDone();
    score_top();
    
    pros::delay(200);
    scraper_toggled();

    // parking

    chassis.moveToPoint(-30,-70,1100,{true,100,0,1});
    pros::delay(230);
    chassis.turnToHeading(90,750);
    pros::delay(500);
    ReAlign(4);
    chassis.moveToPoint(30,-74,1100,{true,90,0,1});
    pros::delay(500);
   }

   void pid_testing(){
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,20,2500,{true,45,0,1});
    pros::delay(1500);
    chassis.turnToHeading(90,2000);
    pros::delay(3000);
    chassis.moveToPoint(48,20,2500,{true,45,0,1});
    pros::delay(1500);
    chassis.turnToHeading(180,2000);
    pros::delay(3000);
    chassis.moveToPoint(48,0,2500,{true,45,0,1});
    pros::delay(1500);
    chassis.turnToHeading(270,2000);
    pros::delay(3000);
    chassis.moveToPoint(0,0,2500,{true,45,0,1});
    pros::delay(1500);
    chassis.turnToHeading(360,2000);
    pros::delay(3000);
   }
    
    
   void straight_testing(){
    chassis.setPose(0,0,0);
    pros::delay(3500);
    chassis.moveToPoint(0,48,2500,{true,60,0,1});
    pros::delay(5000);
    chassis.moveToPoint(0,0,2500,{false,60,0,1});
    pros::delay(5000);
   }