#pragma once
#include "pros/motors.hpp"

extern int TOP;
extern pros::Motor bottom_rollers;
extern pros::Motor top_rollers;

void loading();
void score_top();
void score_bottom();
void changeSpeeds();
void stop();