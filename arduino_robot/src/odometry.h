/*
 * odometry.h
 *
 *  Created on: 19 mars 2018
 *      Author: elie
 * 		Modifié par Jonathan Muchler, 2021
 */
#include "params.h"
#include "encoderRead.h"

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

/* Odometry receive data from encoders, and provide methods with calculated estimated x, y, angle from these encoders */
class Odometry
{
	public:
		/**
		 * @brief Construct a new Odometry object, makes sure that encoder_left and encoder_right are the right one
		 * 
		 * @param encoder_left 
		 * @param encoder_right 
		 * @param wheel_base 
		 */
		Odometry(EncoderRead* encoder_left, EncoderRead* encoder_right, const float wheel_base);
		~Odometry();

		void set_pos(float x, float y, float theta); //dans un référentiel local du robot (0,0 au départ)
		float normalizeAngle(float angle);

		float get_pos_x();
		float get_pos_y();
		float get_pos_theta();
		float get_speed();
		float get_omega();

		void update_pos();
		void init();


		int nbr1;
		int nbr2;
	private:
		const float wheel_base;
		EncoderRead* encoder_left;
		EncoderRead* encoder_right;

		float pos_x, pos_y, pos_theta;

		float speed, omega;

	
};

#endif /* ODOMETRY_H_ */
