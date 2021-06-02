#ifndef VEC2_H
#define VEC2_H
#include <iostream>

namespace math {

struct vec2 {
    float x, y;

    vec2();
    vec2(float, float);
    vec2(const vec2&);

    vec2& add(const vec2&);
    friend vec2 operator+(const vec2&, const vec2&);
    vec2& subtract(const vec2&);
    friend vec2 operator-(const vec2&, const vec2&);
    vec2& multiply(const vec2&);
    friend vec2 operator*(const vec2&, const vec2&);
    vec2& divide(const vec2&);
    friend vec2 operator/(const vec2&, const vec2&);

    friend vec2& operator+=(vec2&, const vec2&);
    friend vec2& operator-=(vec2&, const vec2&);
    friend vec2& operator*=(vec2&, const vec2&);
    friend vec2& operator/=(vec2&, const vec2&);
    friend bool operator==(const vec2&, const vec2&);
    friend bool operator!=(const vec2&, const vec2&);
    friend std::ostream& operator<<(std::ostream&, const vec2 &);
};

std::ostream& operator<<(std::ostream&, const vec2 &);

vec2 operator+(const vec2&, const vec2&);
vec2 operator-(const vec2&, const vec2&);
vec2 operator*(const vec2&, const vec2&);
vec2 operator/(const vec2&, const vec2&);
vec2& operator+=(vec2&, const vec2&);
vec2& operator-=(vec2&, const vec2&);
vec2& operator*=(vec2&, const vec2&);
vec2& operator/=(vec2&, const vec2&);
bool operator==(const vec2&, const vec2&);
bool operator!=(const vec2&, const vec2&);

};

#endif
