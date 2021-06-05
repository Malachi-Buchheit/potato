#include "buffer.h"

using namespace graphics;

Buffer::Buffer(GLfloat *data, GLsizei count, GLuint component_count) 
    : component_count(component_count) {
    glGenBuffers(1, &buffer_id);
    bind();
    glBufferData(GL_ARRAY_BUFFER, count*sizeof(GLfloat), data, GL_STATIC_DRAW);
    unbind();
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &buffer_id);
}

void Buffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

void Buffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
