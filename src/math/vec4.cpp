#include "vec4.h"

using namespace math;
/*
vec4::vec4() {
    x = y = z = w = 0.0f;
}
*/
vec4::vec4(float x_inp, float y_inp, float z_inp, float w_inp) {
    x = x_inp;
    y = y_inp;
    z = z_inp;
    w = w_inp;
}

vec4::vec4(const vec4& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

vec4& vec4::add(const vec4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}
vec4 math::operator+(const vec4& l, const vec4& r) {
    return (vec4(l)).add(r);
}

vec4& vec4::subtract(const vec4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}
vec4 math::operator-(const vec4& l, const vec4& r) {
    return vec4(l).subtract(r);
}

vec4& vec4::multiply(const vec4& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
}
vec4 math::operator*(const vec4& l, const vec4& r) {
    return vec4(l).multiply(r);
}

vec4& vec4::divide(const vec4& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w /= v.w;
    return *this;
}
vec4 math::operator/(const vec4& l, const vec4& r) {
    return vec4(l).divide(r);
}

std::ostream& math::operator<<(std::ostream& stream, const vec4 &v) {
    stream << "vec4: (" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return stream;
}

vec4& math::operator+=(vec4& l, const vec4& r) {
    return l.add(r);
}

vec4& math::operator-=(vec4& l, const vec4& r) {
    return l.subtract(r); 
}

vec4& math::operator*=(vec4& l, const vec4& r) {
    return l.multiply(r);
}

vec4& math::operator/=(vec4& l, const vec4& r) {
    return l.divide(r);
}

bool math::operator==(const vec4& l, const vec4& r) {
    return l.x == r.x && l.y == r.y && l.z == r.z && l.w == r.w;
}

bool operator!=(const vec4& l, const vec4& r) {
    return !(l == r);
}
