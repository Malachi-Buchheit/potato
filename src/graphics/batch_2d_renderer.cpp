#include "batch_2d_renderer.h"

using namespace graphics;

void Batch2DRenderer::init() {
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
    glEnableVertexAttribArray(SHADER_COLOR_INDEX);
    glVertexAttribPointer(
        SHADER_VERTEX_INDEX, 
        3, 
        GL_FLOAT, 
        GL_FALSE, 
        RENDERER_VERTEX_SIZE, 
        (const GLvoid*)0
    );
    glVertexAttribPointer(
        SHADER_COLOR_INDEX, 
        4, 
        GL_FLOAT, 
        GL_FALSE, 
        RENDERER_VERTEX_SIZE, 
        (const GLvoid*)(3*sizeof(GLfloat))
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLushort indices[RENDERER_INDICES_SIZE];

    int offset = 0;
    for(int i = 0; i < RENDERER_INDICES_SIZE; i+=6) {
        indices[i+0] = offset + 0;
        indices[i+1] = offset + 1;
        indices[i+2] = offset + 2;
        indices[i+3] = offset + 1;
        indices[i+4] = offset + 2;
        indices[i+5] = offset + 3;
        offset += 4;
    }

    IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
    glBindVertexArray(0);
}

Batch2DRenderer::~Batch2DRenderer() {
    delete IBO;
    glDeleteBuffers(1, &VBO);
}

void Batch2DRenderer::begin() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void Batch2DRenderer::submit(const Renderable2D *renderable) {
    const math::vec3 &pos = renderable->getPos();
    const math::vec2 &size = renderable->getSize();
    const math::vec4 &color = renderable->getColor();

    buffer->vertex = pos;
    buffer->color = color;
    buffer++;

    buffer->vertex = math::vec3(pos.x+size.x, pos.y, pos.z);
    buffer->color = renderable->getColor();
    buffer++;

    buffer->vertex = math::vec3(pos.x, pos.y+size.y, pos.z);
    buffer->color = renderable->getColor();
    buffer++;

    buffer->vertex = math::vec3(pos.x+size.x, pos.y+size.y, pos.z);
    buffer->color = renderable->getColor();
    buffer++;

    index_count += 6;
}

void Batch2DRenderer::end() {
    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Batch2DRenderer::flush() {
    glBindVertexArray(VAO);
    IBO->bind();
    glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_SHORT, NULL);
    IBO->unbind();
    glBindVertexArray(0);
    index_count = 0;
}
