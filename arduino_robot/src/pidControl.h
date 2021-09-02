/*
    Author : Jonathan Muchler
    Created : September 2021
*/

#pragma once

#include "Encoder.h"

class pidControl {
    public:
        pidControl(double min, double max, double Kp, double Kd, double Ki, Encoder* encoder);
       
        void init();
        void update();
        double getOutput(); //output from the PID | for example : value to set to the motor
       
        void setCons(double value);
        double getCons();

        double get_Kp();
        double get_Kd();
        double get_Ki();

        double set_Kp();
        double set_Kd();
        double set_Ki();
    
    private:
        Encoder* _encoder;

        double _target;
        double _measure;
        double _max;
        double _min;

        double _Kp;
        double _Kd;
        double _Ki;

        double _prev_speed_error=0;
        double _integral_error=0;
		double _delta_speed=0; //proportionnal error
		float _rate_error=0;

};