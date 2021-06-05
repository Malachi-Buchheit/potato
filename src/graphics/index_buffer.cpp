#include "index_buffer.h"

using namespace graphics;

IndexBuffer::IndexBuffer(GLushort *data, GLsizei count) 
    : count(count) {
    glGenBuffers(1, &buffer_id);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLushort), data, GL_STATIC_DRAW);
    unbind();
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &buffer_id);
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
}

void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
