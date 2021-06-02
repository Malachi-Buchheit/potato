#pragma once
#include "renderable_2d.h"
#include "math.h"
#include </usr/include/GL/glew.h>

namespace graphics {

class Renderer2D {
    protected:
    virtual void submit(const Renderable2D *renderable) = 0;
    virtual void flush() = 0;
};

};