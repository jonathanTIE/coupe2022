#include "pidControl.h"
#include "utils.h"


pidControl::pidControl(double min, double max, double Kp, double Kd, double Ki, Encoder* encoder) {
    _min = min;
    _max = max;
    _Kp = Kp;
    _Kd = Kd;
    _Ki = Ki;
    _encoder = encoder;
}

void pidControl::init() {
    _encoder->write(0);
    _measure = 0.0f;
}

void pidControl::update() {
    float cur_speed = _encoder->read();

    double error_speed = _target - cur_speed;
    _integral_error += error_speed;
    _delta_speed = error_speed - _prev_speed_error;
    _prev_speed_error = _integral_error;

    double cmd_speed = _Kp * error_speed + _Ki * _integral_error + _Kd * _delta_speed;
    double motor_speed = clamp(_min, _max, cmd_speed);

		analogWrite(MOT1_PWM, abs(cmd_mot1));
		digitalWrite(MOT1_DIR, direction_sign(cmd_mot1));
		analogWrite(MOT2_PWM, abs(cmd_mot2));
		digitalWrite(MOT2_DIR, direction_sign(cmd_mot2));
}

double pidControl::getTarget(double value) {
    
}

void pidControl::setTarget(double value) {
    
}

double pidControl::get_Kp() {
    
}

double pidControl::get_Kd() {
    
}

double pidControl::get_Ki() {
    
}

double pidControl::set_Kp() {
    
}

double pidControl::set_Kd() {
    
}

double pidControl::set_Ki() {
    
}
