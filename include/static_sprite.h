#pragma once
#include "renderable_2d.h"

namespace graphics {

class StaticSprite : public Renderable2D {
    private:
    VertexArray* vertex_array;
    IndexBuffer* index_buffer;
    Shader &shader;
    public:
    StaticSprite(float x, float y, float w, float h, math::vec4 color, Shader &shader);
    ~StaticSprite();

    inline const VertexArray* getVAO() const {return vertex_array;}
    inline const IndexBuffer* getIBO() const {return index_buffer;}
    inline Shader& getShader() const {return shader;}
};

};
