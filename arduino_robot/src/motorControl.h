/*
 * motorControl.h
 *
 *  Created on: 20 mars 2018
 *      Author: elie
 */

/*
	TODO : Ajouter un timeout (de 200ms) quand une consigne n'a pas été recue, de s'arreter (au cas où nav2 ou la raspberry tombe en panne)
	Ajouter des speed/omega max par sécurité
*/

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include "odometry.h"

//#define DEBUG_ASSERVISSEMENT

class MotorControl {
	public:

		MotorControl(Odometry odometry);
		~MotorControl();
		void update();
		void init();

		float get_cons_speed();
		float get_cons_omega();

		void testmoteur(int cmde1, int cmde2);
		void set_cons(float speed, float omega);

		//void set_ki_speed(); //TODO : rendre accessible l'asserv pour le modifier en live via raspberry


	private:
		float cons_speed=0;
		float cons_omega=0;
		
		float Ki_speed = 0.15; //0.2
		float Kp_speed = 0.4; //0.5
		float Kd_speed = 0.05; //0.2
		float Ki_omega = 10;//15;
		float Kp_omega = 40;//10;
		float Kd_omega = 10;//10;
		
		float error_integrale_speed=0.01;
		float error_integrale_omega=0;

		float delta_speed=0;
		float delta_omega=0;
		float prev_speed_error=0;
		float prev_omega_error=0;
};



#endif /* MOTORCONTROL_H_ */
