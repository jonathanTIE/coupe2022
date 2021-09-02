/**
 * @file Secondary2021.cpp
 * @author jonathan Muchler
 * @brief 
 * @date 2021-06-12
 * 
 * @image html vue_globale_code_2021.png "vue globale du code - au debut juin 2021"
 */

#include "Arduino.h" 
#include "odometry.h"
#include "motorControl.h" 
#include "params.h" 
#include "Metro.h"

#include "communication.h"
#include "actuatorSupervisor.h"


#include "examples/servoTest.h" 
#include "examples/asservissementMoteur.h" 
#include "examples/debugTest.h" 
#include "examples/testXbee.h" 


Metro controlTime = Metro((unsigned long)(CONTROL_PERIOD * 1000));
Metro debugLed = Metro(2000);
Metro commXBee = Metro((unsigned long)(COMMUNICATION_PERIOD * 1000));

Odometry odometry_wheel = Odometry(WHEEL_ENCODEUR1_A,WHEEL_ENCODEUR1_B, WHEEL_ENCODEUR2_A,WHEEL_ENCODEUR2_B, 
	CODER_INCR_TO_MM_1, CODER_INCR_TO_MM_2, CODER_WHEEL_BASE, false);
Odometry odometry_motor = Odometry(MOT_ENCODEUR1_A,MOT_ENCODEUR1_B, MOT_ENCODEUR2_A,MOT_ENCODEUR2_B, 
	INCR_TO_MM_1, INCR_TO_MM_2, WHEELBASE, true);

  
void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(24, INPUT_PULLUP); //tirette
  //testXbee::init();
  Serial2.begin(57600); //UART
  Serial.begin(57600);


  
  //while(!Serial) {} 


  controlTime.reset();
	debugLed.reset();
	odometry_motor.init();
  odometry_wheel.init();
	MotorControl::init();
  ActuatorSupervisor::init();


  //debugTest::scanSerial();
  displayController.init();

  //while (!Serial);
  SerialCtrl.println("test serialctrl");
  Serial.println("test serial");
  //ActuatorSupervisor::switch_pompe(true, 0);
  //navigator.move_to(500.f, 0.f);
  //pwm.begin();

  //Serial2.println("Scanner debut");
  //debugTest::scanSerial();
}

void loop() {
 
 if(debugLed.check())
 {
    
   /*while(Serial1.available())
   {
     Serial1.flush();
   }*/
 }

  //testXbee::update();
    

		if(controlTime.check()) {
      Odometry::update_reading(&odometry_motor, &odometry_wheel);
      MotorControl::update();
		} 

    
    if(commXBee.check())
    {
      Communication::update();
    }

 
    if(TestTime.check())
    {
      //asservissementMoteur::update();
    }




  
} 
