#include "static_sprite.h"

using namespace graphics;

StaticSprite::StaticSprite(float x, float y, float w, float h, math::vec4 color, Shader &shader)
    : Renderable2D(math::vec3(x, y, 0), math::vec2(w, h), color), shader(shader) {
    vertex_array = new VertexArray();
        GLfloat verticies[] {
            0, 0, 0,
            w, 0, 0,
            0, h, 0,
            w, h, 0
        };
        GLfloat colors[] {
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w
        };
        vertex_array->add_buffer(new Buffer(verticies, 4*3, 3), 0);
        vertex_array->add_buffer(new Buffer(colors, 4*4, 4), 1);
        GLushort indicies[] {0, 1, 2, 1, 2, 3};
        index_buffer = new IndexBuffer(indicies, 6);
}

StaticSprite::~StaticSprite() {
    delete vertex_array;
    delete index_buffer;
}