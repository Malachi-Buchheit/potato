#include "vec3.h"

using namespace math;

vec3::vec3() {
    x = y = z = 0.0f;
}

vec3::vec3(float x_inp, float y_inp, float z_inp) {
    x = x_inp;
    y = y_inp;
    z = z_inp;
}

vec3::vec3(const vec3& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

vec3& vec3::add(const vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}
vec3 math::operator+(const vec3& l, const vec3& r) {
    return (vec3(l)).add(r);
}

vec3& vec3::subtract(const vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}
vec3 math::operator-(const vec3& l, const vec3& r) {
    return vec3(l).subtract(r);
}

vec3& vec3::multiply(const vec3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}
vec3 math::operator*(const vec3& l, const vec3& r) {
    return vec3(l).multiply(r);
}

vec3& vec3::divide(const vec3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}
vec3 math::operator/(const vec3& l, const vec3& r) {
    return vec3(l).divide(r);
}

std::ostream& math::operator<<(std::ostream& stream, const vec3 &v) {
    stream << "vec3: (" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

vec3& math::operator+=(vec3& l, const vec3& r) {
    return l.add(r);
}

vec3& math::operator-=(vec3& l, const vec3& r) {
    return l.subtract(r); 
}

vec3& math::operator*=(vec3& l, const vec3& r) {
    return l.multiply(r);
}

vec3& math::operator/=(vec3& l, const vec3& r) {
    return l.divide(r);
}

bool math::operator==(const vec3& l, const vec3& r) {
    return l.x == r.x && l.y == r.y && l.z == r.z;
}

bool operator!=(const vec3& l, const vec3& r) {
    return !(l == r);
}
