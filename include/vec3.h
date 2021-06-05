#ifndef VEC3_H
#define VEC3_H
#include <iostream>

namespace math {

struct vec3 {
    float x, y, z;

    vec3();
    vec3(float, float, float);
    vec3(const vec3&);

    vec3& add(const vec3&);
    friend vec3 operator+(const vec3&, const vec3&);
    vec3& subtract(const vec3&);
    friend vec3 operator-(const vec3&, const vec3&);
    vec3& multiply(const vec3&);
    friend vec3 operator*(const vec3&, const vec3&);
    vec3& divide(const vec3&);
    friend vec3 operator/(const vec3&, const vec3&);

    friend vec3& operator+=(vec3&, const vec3&);
    friend vec3& operator-=(vec3&, const vec3&);
    friend vec3& operator*=(vec3&, const vec3&);
    friend vec3& operator/=(vec3&, const vec3&);
    friend bool operator==(const vec3&, const vec3&);
    friend bool operator!=(const vec3&, const vec3&);
    friend std::ostream& operator<<(std::ostream&, const vec3 &);
};

std::ostream& operator<<(std::ostream&, const vec3 &);

vec3 operator+(const vec3&, const vec3&);
vec3 operator-(const vec3&, const vec3&);
vec3 operator*(const vec3&, const vec3&);
vec3 operator/(const vec3&, const vec3&);
vec3& operator+=(vec3&, const vec3&);
vec3& operator-=(vec3&, const vec3&);
vec3& operator*=(vec3&, const vec3&);
vec3& operator/=(vec3&, const vec3&);
bool operator==(const vec3&, const vec3&);
bool operator!=(const vec3&, const vec3&);

};

#endif
