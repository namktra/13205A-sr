#include "matchloader.hpp"
#include "main.h"
#include "pros/misc.h"

pros::adi::DigitalOut scraper('A');
bool enabled = false;

void matchloader_toggled(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
        scraper.set_value(!enabled);
        enabled = !enabled;
    }
}
