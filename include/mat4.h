#ifndef MAT4_H
#define MAT4_H
#include "math.h"
#include <iostream>
#include <iomanip>

namespace math {
struct mat4 {
    union {
        float elem[4*4];
        vec4 cols[4];
        //vec4 rows[4];
    };

    mat4();
    mat4(float diagonal);
    mat4(const mat4 &m);

    static mat4 identity();
    static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
    static mat4 perspective(float fov, float aspect_ratio, float near, float far);
    
    static mat4 rotation(float angle, const vec3 &axis);
    static mat4 translation(const vec3 &translation);
    static mat4 scale(const vec3 &scale);

    mat4 &multiply(const mat4 &);
    
    friend mat4 operator*(const mat4&, const mat4&);
    friend mat4 operator*=(mat4&, const mat4&);
    friend std::ostream &operator<<(std::ostream&, const mat4&);
};

mat4 operator*(const mat4&, const mat4&);
mat4 operator*=(mat4&, const mat4&);
std::ostream &operator<<(std::ostream&, const mat4&);
};

#endif
