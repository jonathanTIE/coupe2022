#include "communication.h"
#include "Arduino.h"
#include <stdlib.h>
#include "motorControl.h"
#include "odometry.h"
#include "params.h"
//#include "actuatorSupervisor.h"


#define COM_DEBUG

namespace Communication {
    
    
    static void parse_data();

    char buffer[50];
    int buff_index=0;
    void update() {
        int a;
        a = SerialCtrl.available();
        
        if (a) {
            
            for (int k=0;k<a;k++) {
                char c=SerialCtrl.read();
                //serialCtrl.write(c);
                if (c=='\n'){
                   
                   buffer[buff_index]='\0';
      //             serialCtrl.write(buffer,i);
                   parse_data();
                   //value=atoi(buffer);
                   buff_index=0;

                }
                else if (c=='\r') {}
                else {
                    buffer[buff_index]=c;
                    buff_index++;
                }
            }
        }



    }

    static void parse_data(){
        if(buffer[0] == 's') {
            // navigator.forceStop();
            #ifdef COM_DEBUG
            SerialCtrl.println("Stopped!");
            #endif
        }
        else if(buffer[0] == 'm') {
            float x,y;
            int nb = sscanf(buffer, "m %f %f", &x, &y);
            if(nb == 2) {   
                //navigator.move_to(x, y);
                #ifdef COM_DEBUG
                SerialCtrl.print("Moving to ");
                SerialCtrl.print(x);
                SerialCtrl.print("\t");
                SerialCtrl.println(y);
                #endif
            }
        }

        else if(buffer[0] == '1') {
            SerialCtrl.print("pos - absolue :  ");
            //SerialCtrl.print(MatchDirector::get_abs_x());
            SerialCtrl.print("\t");
            //SerialCtrl.println(MatchDirector::get_abs_y());
        } 
        else if(buffer[0] == 't') {
            //in degrees
            float angle;
            int nb = sscanf(buffer, "t %f", &angle);
            if(nb == 1) {
               // navigator.turn_to(angle);
            }
        }

        
        else if(buffer[0] == 'a') {
            float x,y;
            int nb = sscanf(buffer, "a %f %f", &x, &y);
            if(nb == 2) {   
                // MatchDirector::abs_coords_to(x, y);
                #ifdef COM_DEBUG
                SerialCtrl.print("Moving to ");
                SerialCtrl.print(x);
                SerialCtrl.print("\t");
                SerialCtrl.println(y);
                #endif
            }
        }



        buff_index = 0;
    }
}       