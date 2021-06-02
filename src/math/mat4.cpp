#include "mat4.h"
#include "math.h"

using namespace math;

mat4::mat4() {
    for(int i = 0; i < 4*4; i++)
        elem[i] = 0;
}

mat4::mat4(float diagonal) {
    for(int i = 0; i < 4*4; i++)
        elem[i] = 0;
    elem[0 + 0*4] = diagonal;
    elem[1 + 1*4] = diagonal;
    elem[2 + 2*4] = diagonal;
    elem[3 + 3*4] = diagonal;
}

mat4::mat4(const mat4 &m) {
    for(int i = 0; i < 4*4; i++)
        elem[i] = m.elem[i];
}

mat4 &mat4::multiply(const mat4 &m) {
    mat4 out(*this);
    float num;
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            num = 0;
            for(int i = 0; i < 4; i++)
                num += elem[x + i*4] * m.elem[i + y*4];
            out.elem[y + x*4] = num;
        }
    }
    *this = out;
    return *this;
}

mat4 math::operator*(const mat4 &l, const mat4 &r) {
    return mat4(l).multiply(r);
}

mat4 math::operator*=(mat4 &l, const mat4 &r) {
    return l.multiply(r);
}

mat4 mat4::identity() {
    return mat4(1);
}

mat4 mat4::orthographic(float left, float right, float top, float bottom, float near, float far) {
    mat4 out(1);
    out.elem[0 + 0*4] = 2/(right-left);
    out.elem[1 + 1*4] = 2/(top-bottom);
    out.elem[2 + 2*4] = 2/(near-far);
    out.elem[0 + 3*4] = (left+right)/(left-right);
    out.elem[1 + 3*4] = (bottom+top)/(bottom-top);
    out.elem[2 + 3*4] = (far+near)/(far-near);
    return out;
}

mat4 mat4::perspective(float fov, float aspect_ratio, float near, float far) {
    mat4 out(1);
    float q = 1/(tan(to_radians(0.5*fov)));
    float a = q / aspect_ratio;
    float b = (near + far) / (near - far);
    float c = (2 * near * far) / (near - far);

    out.elem[0 + 0*4] = a;
    out.elem[1 + 1*4] = q;
    out.elem[2 + 2*4] = b;
    out.elem[3 + 2*4] = -1;
    out.elem[2 + 3*4] = c;

    return out;
}

mat4 mat4::rotation(float angle, const vec3 &axis) {
    mat4 out(1);

    float r = to_radians(angle);
    float c = cos(r);
    float s = sin(r);
    float omc = 1 - c;

    out.elem[0 + 0*4] = axis.x * omc + c;
    out.elem[1 + 0*4] = axis.y * axis.x * omc + axis.z * s;
    out.elem[2 + 0*4] = axis.z * axis.x * omc + axis.y * s;

    out.elem[0 + 1*4] = axis.x * axis.y - axis.z * s;
    out.elem[1 + 1*4] = axis.y * omc + c;
    out.elem[2 + 1*4] = axis.y * axis.z * omc + axis.x * s;

    out.elem[0 + 2*4] = axis.x * axis.z * omc + axis.y * s;
    out.elem[1 + 2*4] = axis.y * axis.z * omc - axis.x * s;
    out.elem[2 + 2*4] = axis.z * omc + c;

    return out;
}

mat4 mat4::translation(const vec3 &translation) {
    mat4 out(1);
    out.elem[0 + 3*4] = translation.x;
    out.elem[1 + 3*4] = translation.y;
    out.elem[2 + 3*4] = translation.z;
    return out;
}

mat4 mat4::scale(const vec3 &scale) {
    mat4 out(1);
    out.elem[0 + 0*4] = scale.x;
    out.elem[1 + 1*4] = scale.y;
    out.elem[2 + 2*4] = scale.z;
    return out;
}

std::ostream &math::operator<<(std::ostream &out, const mat4 &m) {
    out << "mat4\n|" << std::setw(3) << m.elem[0];
    for(int i = 1; i < 15; i++) {
        if(i%4 == 0)
            out << "|\n|";
        else
            out << " ";
        out << std::setw(3) << m.elem[i];
    }
    out << " " << std::setw(3) << m.elem[15] << "|";
    return out;
}
