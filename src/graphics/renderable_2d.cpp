#include "renderable_2d.h"

using namespace graphics;

Renderable2D::Renderable2D(math::vec3 pos, math::vec2 size, math::vec4 color) 
    : pos(pos), size(size), color(color) {}

Renderable2D::~Renderable2D() {}
