#pragma once
#include <deque>
#include "renderer2d.h"
#include "index_buffer.h"

namespace graphics {

#define RENDERER_MAX_SPRITES 10000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE (RENDERER_VERTEX_SIZE * 4)
#define RENDERER_BUFFER_SIZE (RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES)
#define RENDERER_INDICES_SIZE (RENDERER_MAX_SPRITES * 6)
#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

class Batch2DRenderer : public Renderer2D {
    private:
    std::deque<const Renderable2D*> render_queue;

    GLuint VAO;
    GLuint VBO;
    VertexData* buffer;
    IndexBuffer *IBO;
    GLsizei index_count;

    public:
    Batch2DRenderer() {init();}
    ~Batch2DRenderer();
    void begin();
    void submit(const Renderable2D *renderable) override;
    void end();
    void flush() override;

    private:
    void init();
};

};
