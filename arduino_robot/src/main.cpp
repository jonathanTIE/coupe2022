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
#include "Encoder.h"
#include "encoderRead.h"
#include "Metro.h"

#include "params.h" 

#include "communication.h"
//#include "actuatorSupervisor.h"

//#include "examples/servoTest.h" 
//#include "examples/asservissementMoteur.h" 
//#include "examples/debugTest.h" 
//#include "examples/testXbee.h" 


Metro controlTime = Metro((unsigned long)(CONTROL_PERIOD * 1000));
Metro debug = Metro(2000);
Metro commXBee = Metro((unsigned long)(COMMUNICATION_PERIOD * 1000));




//create_odometry_motor

  Encoder motor1_coder = Encoder(MOT_ENCODEUR1_A, MOT_ENCODEUR1_B);
  Encoder motor2_coder = Encoder(MOT_ENCODEUR2_A,MOT_ENCODEUR2_B);
  EncoderRead mot1_read = EncoderRead(&motor1_coder, INCR_TO_MM_1);
  EncoderRead mot2_read = EncoderRead(&motor2_coder, INCR_TO_MM_2);
  Odometry odometry_motor = Odometry(&mot1_read, &mot2_read, WHEELBASE);
  //Odometry odometry_wheel = create_odometry_coder();
  MotorControl motorControl = MotorControl(&odometry_motor);

//Odometry create_odometry_coder()
//{
  //return NULL;
    //Odometry odometry_wheel = Odometry(WHEEL_ENCODEUR1_A,WHEEL_ENCODEUR1_B, WHEEL_ENCODEUR2_A,WHEEL_ENCODEUR2_B, 
	//CODER_INCR_TO_MM_1, CODER_INCR_TO_MM_2, CODER_WHEEL_BASE, false);
//}
void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(24, INPUT_PULLUP); //tirette
  //testXbee::init();



  Serial2.begin(57600); //UART
  Serial.begin(57600);



  
  //while(!Serial) {} 


  controlTime.reset();
	debug.reset();

	odometry_motor.init();
  //ActuatorSupervisor::init();

  //debugTest::scanSerial();

  //while (!Serial);
  SerialCtrl.println("test serialctrl");
  Serial.println("test serial");
  
}

void loop() {
 
  if(debug.check())
  {
      
    /*while(Serial1.available())
    {
      Serial1.flush();
    }*/
          //asservissementMoteur::update();
  }
    

  if(controlTime.check()) {
    //updating encoder reading
    mot1_read.update();
    mot2_read.update();

  //calculating odometry
    odometry_motor.update_pos();

  //sending new commands
    motorControl.update();
  } 

  
  if(commXBee.check())
  {
    Communication::update();
  }
  
} 
