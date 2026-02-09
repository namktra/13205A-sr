#include "main.h"


pros::adi::DigitalOut scraper('A');
pros::adi::DigitalOut descore('B');
pros::adi::DigitalOut middle('C');
bool enabled_ml = true;
bool enabled_ds = false;
bool enabled_mid = true;


void scraper_toggled(){
        scraper.set_value(!enabled_ml);
        enabled_ml = !enabled_ml;
}

void descore_toggled(){
        descore.set_value(!enabled_ds);
        enabled_ds = ! enabled_ds;
}

void middle_toggled(){
        middle.set_value(!enabled_mid);
        enabled_mid = !enabled_mid;
}

