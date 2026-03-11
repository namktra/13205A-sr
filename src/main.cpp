#include "main.h"
#include "autonomous.hpp"
#include "intake.hpp"
#include "pneumatics.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "selector/auton_selector.hpp"
#include <type_traits>

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftMotors({-8, -5, -17},pros::MotorGearset::blue); // left motor group - ports 3 (reversed), 4, 5 (reversed)
pros::MotorGroup rightMotors({7, 18, 2}, pros::MotorGearset::blue); // right motor group - ports 6, 7, 9 (reversed)

// Inertial Sensor on port 10
pros::Imu imu(14);

// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
// pros::Rotation horizontalEnc(20);

// vertical tracking wheel encoder. Rotation sensor, port 11, reversed
pros::Rotation verticalEnc(9);
// // horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
// lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_2, -5.75);

// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_2, -1.5);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              13.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              8 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            60.5, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            1.5, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(5, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             40.5, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            nullptr, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(7, // joystick deadband out of 127
                                     7, // minimum output where drivetrain will move out of 127
                                     1.002 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(1, // joystick deadband out of 127
                                  1, // minimum output where drivetrain will move out of 127
                                  1.02 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    
    chassis.setPose(0,0,0);
    enabled_lp = true;
    l_piston.set_value(true);
    enabled_mid = false;
    middle.set_value(true);
    scraper.set_value(true);
    enabled_ml = true;
    descore.set_value(false);
    enabled_ds = false;
    controller.set_text(0,0,"Middle Disabled");

    // pros::Task middleControl([]{
    //     while(true){
    //         changeSpeeds();
    //         if(enabled_mid && scoringOn){
    //             middle.set_value(false);
    //             l_piston.set_value(false);
    //         } else {
    //             middle.set_value(true);
    //             l_piston.set_value(true);
    //         }
    //         pros::delay(10);
    //     }
    // });


    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 * This is an example autonomous routine w  
 which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
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
    chassis.moveToPoint(-56,currY, 1500,{.forwards = true,.maxSpeed = 57,.minSpeed = 1, .earlyExitRange = 0});
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
    chassis.moveToPoint(-64,-32, 2500,{true,80,0,1},false);
    ReAlign(4);
    pros::delay(500);
    chassis.moveToPoint(-47.5,-47, 1750,{true,60,0,1},false);
    pros::delay(250);
    chassis.turnToHeading(90, 750,{},false);
    ReAlign(4);
    pros::delay(400);
    chassis.turnToHeading(180, 750,{},false);
    ReAlign(4);
    pros::delay(400);
    chassis.moveToPoint(currX,-23, 1750,{false,70,0,1},false);
    score_top();
    scraper_toggled();
    pros::delay(2100);
  
    // loading();
    // chassis.moveToPoint(currX,-70, 1750,{true,70,0,1},false);
    // pros::delay(2200);
    // chassis.moveToPoint(currX,-23, 1250,{false,60,0,1},false);
    // score_top();
    // pros::delay(2000);

    // chassis.moveToPoint(-30,-70,1100,{true,100,0,1},false);
    // pros::delay(230);
    // chassis.turnToHeading(90,750,{},false);
    // pros::delay(500);
    // ReAlign(4);
    // chassis.moveToPoint(30,-74,1100,{true,90,0,1},false);


  
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // controller
    // loop to continuously update motors
    while (true) {
        
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX);
        chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);




        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
            loading();
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
            
            score_top();
            scoringOn = true;
            
    
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            score_bottom();
        } else {
            stop();
            scoringOn = false;
        }
        
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
            scraper_toggled();
        } else 
        {}

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
            middle_toggled();
        } else 
        {}

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
            descore_toggled();
        } else 
        {}

        pros::delay(10);
    }
}