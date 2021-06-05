#include "vertex_array.h"

using namespace graphics;

VertexArray::VertexArray() {
    glGenVertexArrays(1, &array_id);
}

VertexArray::~VertexArray() {
    for(auto b : buffers)
        delete b;
    glDeleteVertexArrays(1, &array_id);
}

void VertexArray::add_buffer(Buffer *buffer, GLuint index) {
    bind();
    buffer->bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
    buffer->unbind();
    unbind();
}

void VertexArray::bind() const {
    glBindVertexArray(array_id);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}