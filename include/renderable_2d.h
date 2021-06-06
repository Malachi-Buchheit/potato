#pragma once
#include "buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "math.h"

namespace graphics {

struct VertexData {
    math::vec3 vertex;
    //math::vec4 color;
    unsigned int color;
};

class Renderable2D {
    protected:
    math::vec3 pos;
    math::vec2 size;
    math::vec4 color;
    
    public:
    Renderable2D(math::vec3 pos, math::vec2 size, math::vec4 color);
    virtual ~Renderable2D();

    inline const math::vec3 getPos() const {return pos;}
    inline const math::vec2 getSize() const {return size;}
    inline const math::vec4 getColor() const {return color;}
};

};
