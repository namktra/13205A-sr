#include "main.h"


pros::adi::DigitalOut scraper('A');
pros::adi::DigitalOut descore('B');
pros::adi::DigitalOut middle('C');
pros::adi::DigitalOut l_piston('D');
bool enabled_ml = false;
bool enabled_ds = false;
bool enabled_mid = true;
bool enabled_lp = true;

void scraper_toggled(){
        scraper.set_value(!enabled_ml);
        enabled_ml = !enabled_ml;
}

void descore_toggled(){
        descore.set_value(!enabled_ds);
        enabled_ds = ! enabled_ds;
}

void middle_toggled(){
        enabled_mid = !enabled_mid;
        if(enabled_mid){
                controller.set_text(0,0,"Middle Enabled");
        } else {
                controller.set_text(0,0,"Middle Disabled");
        }
}

