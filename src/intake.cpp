#include "main.h"

// motor speeds

int TOP = 110;

pros::Motor bottom_rollers(15, pros::v5::MotorGears::blue);
pros::Motor top_rollers(16,pros::v5::MotorGears::blue);

void loading(){
    top_rollers.move(127);
    bottom_rollers.move(35);
}

void score_bottom(){
    bottom_rollers.move(-127);
    top_rollers.move(-90);
}

void score_top(){
    bottom_rollers.move(-110);
    top_rollers.move(110);
}

void stop(){
    bottom_rollers.move(0);
    top_rollers.move(0);
}

void changeSpeeds(){
    if (enabled_mid == false){
        TOP = -117;
    } else if (enabled_mid == true){
        TOP = -80;
    }
}


