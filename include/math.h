#ifndef MATH_H
#define MATH_H
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include </usr/include/math.h>

namespace math {

inline float to_radians(float deg) {
    return deg*M_PI/180;
}

};

#endif