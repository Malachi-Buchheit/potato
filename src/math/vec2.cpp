#include "vec2.h"

using namespace math;

vec2::vec2() {
    x = y = 0.0f;
}

vec2::vec2(float x_inp, float y_inp) {
    x = x_inp;
    y = y_inp;
}

vec2::vec2(const vec2& v) {
    x = v.x;
    y = v.y;
}

vec2& vec2::add(const vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}
vec2 math::operator+(const vec2& l, const vec2& r) {
    return (vec2(l)).add(r);
}

vec2& vec2::subtract(const vec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}
vec2 math::operator-(const vec2& l, const vec2& r) {
    return vec2(l).subtract(r);
}

vec2& vec2::multiply(const vec2& v) {
    x *= v.x;
    y *= v.y;
    return *this;
}
vec2 math::operator*(const vec2& l, const vec2& r) {
    return vec2(l).multiply(r);
}

vec2& vec2::divide(const vec2& v) {
    x /= v.x;
    y /= v.y;
    return *this;
}
vec2 math::operator/(const vec2& l, const vec2& r) {
    return vec2(l).divide(r);
}

std::ostream& math::operator<<(std::ostream& stream, const vec2 &v) {
    stream << "vec2: (" << v.x << ", " << v.y << ")";
    return stream;
}

vec2& math::operator+=(vec2& l, const vec2& r) {
    return l.add(r);
}

vec2& math::operator-=(vec2& l, const vec2& r) {
    return l.subtract(r); 
}

vec2& math::operator*=(vec2& l, const vec2& r) {
    return l.multiply(r);
}

vec2& math::operator/=(vec2& l, const vec2& r) {
    return l.divide(r);
}

bool math::operator==(const vec2& l, const vec2& r) {
    return l.x == r.x && l.y == r.y;
}

bool operator!=(const vec2& l, const vec2& r) {
    return !(l == r);
}
