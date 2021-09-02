/*


*/

#include "params.h"
#include "Encoder.h"

/**
 * @brief store the mm traveled by a wheel (either coder or motor, as long as there is an encoder)
 * 
 * @warning there are usually problem with using interruption (like with encoder) in a class, so keep it hardcoded that way (in a namespace)
 */


/*To add other encoders :
Encoder NAME(PIN1, PIN2);
float NAME_dist;
float NAME_speed;
*/

namespace EncoderRead{
    Encoder motor1_coder(MOT_ENCODEUR1_A, MOT_ENCODEUR1_B);

    float motor1_dist; //distance traveled
    float motor1_speed;

    void update()
    {
        if(MOT_ENCODEUR1_A != 0)
        {
            int32_t reading = motor1_coder.read() * INCR_TO_MM_1;
            motor1_dist += reading;
            motor1_speed = reading; //could be modified to average values from previous readings
            motor1_coder.write(0);
        }
    }
}