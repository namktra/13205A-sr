#include "pros/distance.hpp"
#include "main.h"

pros::Distance side(2);
pros::Distance back(3);

double offsetSide = 0;
double offsetBack = 0;

void ReAlign(int quadrant){
    double sideReading = side.get() + offsetSide;
    double backReading = back.get() + offsetBack;

    Pose curr = chassis.getPose();
    double currHeading = curr.theta;
    double currX = curr.x;
    double currY = curr.y;

    int direction;
    if(currHeading > 315 && currHeading <= 45){direction = 1;}
    if(currHeading > 45 && currHeading <= 135){direction = 2;}
    if(currHeading > 135 && currHeading <= 225){direction = 3;}
    if(currHeading > 225 && currHeading <= 315){direction = 4;}

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



    

}

