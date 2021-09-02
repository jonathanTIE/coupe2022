#pragma once

#include <Arduino.h>
#ifndef UTILS_H
#define UTILS_H




template<typename T> 
const T & clamp( const T & inf, const T & sup, const T & x ) 
{ 
    return min(sup, max(inf, x));
}

int direction_sign(int nb) {
	if(nb>0) {
		return 0;
	}
	else {
		return 1;
	}
}

#endif
