#pragma once
#include "renderable_2d.h"

namespace graphics {

class Sprite : public Renderable2D {
    public:
    Sprite(float x, float y, float w, float h, math::vec4 color);
};

};
