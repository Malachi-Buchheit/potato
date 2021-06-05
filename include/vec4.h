#ifndef VEC4_H
#define VEC4_H
#include <iostream>

namespace math {

struct vec4 {
    float x, y, z, w;

    //vec4();
    vec4() = default;
    vec4(float, float, float, float);
    vec4(const vec4&);

    vec4& add(const vec4&);
    friend vec4 operator+(const vec4&, const vec4&);
    vec4& subtract(const vec4&);
    friend vec4 operator-(const vec4&, const vec4&);
    vec4& multiply(const vec4&);
    friend vec4 operator*(const vec4&, const vec4&);
    vec4& divide(const vec4&);
    friend vec4 operator/(const vec4&, const vec4&);

    friend vec4& operator+=(vec4&, const vec4&);
    friend vec4& operator-=(vec4&, const vec4&);
    friend vec4& operator*=(vec4&, const vec4&);
    friend vec4& operator/=(vec4&, const vec4&);
    friend bool operator==(const vec4&, const vec4&);
    friend bool operator!=(const vec4&, const vec4&);
    friend std::ostream& operator<<(std::ostream&, const vec4 &);
};

std::ostream& operator<<(std::ostream&, const vec4 &);

vec4 operator+(const vec4&, const vec4&);
vec4 operator-(const vec4&, const vec4&);
vec4 operator*(const vec4&, const vec4&);
vec4 operator/(const vec4&, const vec4&);
vec4& operator+=(vec4&, const vec4&);
vec4& operator-=(vec4&, const vec4&);
vec4& operator*=(vec4&, const vec4&);
vec4& operator/=(vec4&, const vec4&);
bool operator==(const vec4&, const vec4&);
bool operator!=(const vec4&, const vec4&);

};

#endif
