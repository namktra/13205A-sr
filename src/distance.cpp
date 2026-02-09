
#include "pros/distance.hpp"
#include "main.h"

pros::Distance side(2);
pros::Distance back(3);



double offsetSide = 4.5;
double offsetBack = 4.8;

lemlib::Pose curr = chassis.getPose();
double currHeading = curr.theta;
double currX = curr.x;
double currY = curr.y;



void ReAlign(int quadrant){

    // taking the readings from the sensors; 
    // the offset is the distance from the sensor to middle of the bot ||  NEEDS CHANGING
    double sideReading = side.get() * (0.03937007874) + offsetSide;
    double backReading = back.get() * (0.03937007874) + offsetBack;


    // takes the current position and saves them into variables
    curr = chassis.getPose();
    currHeading = curr.theta;
    currX = curr.x;
    currY = curr.y;
    
    // figuring out the orientation of the robot based on heading
    int direction;
    if(currHeading > 315 && currHeading <= 45){direction = 1;}
    if(currHeading > 45 && currHeading <= 135){direction = 2;}
    if(currHeading > 135 && currHeading <= 225){direction = 3;}
    if(currHeading > 225 && currHeading <= 315){direction = 4;}


    // recalculating the true position of the robot on the field in relation 
    // to its current quadrant and orientation (direction)
    if(quadrant == 1){
        
        if(direction == 1){chassis.setPose(currX, 0 - (72-backReading),currHeading);}
        if(direction == 3){chassis.setPose(72- sideReading, currY,currHeading);}
        if(direction == 4){chassis.setPose(72-backReading, 0 - (72-sideReading),currHeading);}

    }

    if(quadrant == 2){

        if(direction == 2){chassis.setPose(currX, 72 - sideReading,currHeading);}
        if(direction == 3){chassis.setPose(72 - sideReading, 72 - backReading,currHeading);}
        if(direction == 4){chassis.setPose(72 - backReading, currY,currHeading);}
        
    }

    if(quadrant == 3){
        
        if(direction == 1){chassis.setPose(0 - (72 - sideReading), currY,currHeading);}
        if(direction == 2){chassis.setPose(0 - (72 - backReading), 72 - sideReading,currHeading);}
        if(direction == 3){chassis.setPose(currX, 72 - backReading,currHeading);}
        
    }

    if(quadrant == 4){
        
        if(direction == 1){chassis.setPose(0-(72-sideReading),0-(72-backReading),currHeading);}
        if(direction == 2){chassis.setPose(0-(72-backReading),currY,currHeading);}
        if(direction == 4){chassis.setPose(currX,0-(72-sideReading),currHeading);}
        
    }

    // saving the new positions and printing them to the terminal to debug and check
    curr = chassis.getPose();
    currHeading = curr.theta;
    currX = curr.x;
    currY = curr.y;

    cout << currX << endl;
    cout << currY << endl;
    cout << currHeading << endl;
}

