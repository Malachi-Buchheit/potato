#include "sprite.h"

using namespace graphics;

Sprite::Sprite(float x, float y, float w, float h, math::vec4 color) 
    : Renderable2D(math::vec3(x, y, 0), math::vec2(w, h), color) {}