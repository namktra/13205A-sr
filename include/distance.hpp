#pragma once
#include "pros/distance.hpp"

extern pros::Distance side;
extern pros::Distance back;

extern double offsetSide;
extern double offsetBack;

extern lemlib::Pose curr;
extern double currHeading;
extern double currX;
extern double currY;



void ReAlign(int quadrant);