#pragma once
#include "api.h"




extern pros::adi::DigitalOut scraper;
extern pros::adi::DigitalOut descore;
extern pros::adi::DigitalOut middle;
extern pros::adi::DigitalOut l_piston;
extern bool enabled_ml;
extern bool enabled_ds;
extern bool enabled_mid;
extern bool enabled_lp;

void scraper_toggled();
void descore_toggled();
void middle_toggled();