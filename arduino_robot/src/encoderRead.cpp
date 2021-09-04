#include "encoderRead.h"

EncoderRead::EncoderRead(Encoder* encoder, const float incr_to_mm)
{
    this->encoder = encoder;
    this->incr_to_mm = incr_to_mm;
}
EncoderRead::~EncoderRead()
{

}
/*
void EncoderRead::init()
{
    
}
*/
void EncoderRead::update()
{
    int32_t reading = (*this->encoder).read() * this->incr_to_mm;
    this->dist += reading;
    this->speed = reading; //could be modified to average values from previous readings
    (*this->encoder).write(0);

}

float EncoderRead::get_dist()
{
    return this->dist;
}
float EncoderRead::get_speed()
{
    return this->speed;
}