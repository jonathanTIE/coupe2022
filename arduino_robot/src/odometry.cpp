/*
 * Odometry.cpp
 *
 *  Created on: 19 mars 2018
 *      Author: elie
 * 		Modified by : jonathan
 */
#include "odometry.h"
#include "params.h"
#include "Arduino.h"
#include "motorControl.h"


Odometry::Odometry(EncoderRead* encoder_left, EncoderRead* encoder_right, const float wheel_base):
	wheel_base(wheel_base)
{
	this-> encoder_left = encoder_left;
	this-> encoder_right = encoder_right;
}	

Odometry::~Odometry() {
    
}

void Odometry::init() {
		pos_x = pos_y = pos_theta = speed = omega = 0;

	}

float Odometry::get_pos_x() {
		return pos_x;
	}

float Odometry::get_pos_y() {
		return pos_y;
	}

float Odometry::get_pos_theta() {
		return normalizeAngle(pos_theta);
	}


float Odometry::normalizeAngle(float angle)
{
	float newAngle = angle;
	while (newAngle <= -PI) newAngle += TWO_PI;
	while (newAngle > PI) newAngle -= TWO_PI;
	return newAngle;
}

float Odometry::get_speed() {
		return speed;
	}

float Odometry::get_omega() {
		return omega;
	}

void Odometry::set_pos(float x, float y, float theta) {
		pos_x = x;
		pos_y = y;
		pos_theta = theta;
	}
	


void Odometry::update_pos()
{
		//nbr1 += incr1;
		//nbr2 += incr2;

		/*SerialDebug.print("nbr1 ");
		SerialDebug.print(nbr1);
		SerialDebug.print(" nbr2 ");
		SerialDebug.println(nbr2);*/
		float length;
		float angle; 
		//TODO : vérifier si en dessous c'est cohérent ! 
		//original :
		/*
				if (MotorControl::get_cons_speed()>=0) {
			length = ((float)(incr1*INCR_TO_MM_1+incr2*INCR_TO_MM_2)/2.0);
			angle = ((float)(incr2*INCR_TO_MM_2-incr1*INCR_TO_MM_1))/WHEELBASE;
		}
		else {
			length = ((float)(incr1*INCR_TO_MM_2+incr2*INCR_TO_MM_1)/2.0);
			angle = ((float)(incr2*INCR_TO_MM_1-incr1*INCR_TO_MM_2))/WHEELBASE;
		}
	
		*/
	
		length = ((float)(encoder_left->get_speed() + encoder_right->get_speed())/2.0);
		angle = ((float)(encoder_right->get_speed()-encoder_left->get_speed()))/wheel_base;
		
		pos_x = pos_x + length*cos(pos_theta + angle/2.0); //interpolation entre les deux theta
		pos_y = pos_y + length*sin(pos_theta + angle/2.0);
		pos_theta = pos_theta + angle;
		speed = length / CONTROL_PERIOD;
		omega = angle / CONTROL_PERIOD;
		
		#ifdef DEBUG_ODOMETRY
		SerialDebug.print("x:");
		SerialDebug.print(pos_x);
		SerialDebug.print("\t y:");
		SerialDebug.print(pos_y);
		SerialDebug.print("\t pos_theta:");
		SerialDebug.print(pos_theta);
		SerialDebug.print("\tspeed:");
		SerialDebug.print(speed);
		SerialDebug.print("\treal omega:");
		SerialDebug.println(omega);

		#endif
}
