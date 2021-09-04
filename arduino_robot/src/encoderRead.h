/*


*/

#include "params.h"
#include "Encoder.h"
//TODO : replace encoder with a custom hardware library, (either STM or teensy)

/**
 * @brief store the mm traveled by a wheel (either coder or motor, as long as there is an encoder)
 * 
 * @warning there are usually problem with using interruption (like with encoder) in a class, so keep it hardcoded that way (in a namespace)
 * @warning only documentation made, code doesn't work yet, will depend on the implementation (STM, teensy,...)
 */

#pragma once
//
class EncoderRead {
    public:
        /**
         * @brief Construct a new Encoder Read object
         * 
         * @param encoder TODO/WARNING - change Encoder with a custom hardware library with same signature, and init it before instantiating encoderread(or maybe use an init here which will init the encoder ?)
         */
        EncoderRead(Encoder* encoder, const float incr_to_mm);
        ~EncoderRead();
        void update();

        float get_dist();
        float get_speed();

    private:
        Encoder* encoder;
        float incr_to_mm;

        float dist; //distance traveled
        float speed; //TODO : pour l'instant on garde en speed le dernier reading, peut-être faire une moyenne et avoir une variable last_incr ? (à voir avec odometry comment modif ça)


};