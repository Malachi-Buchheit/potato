#pragma once
#include </usr/include/GL/glew.h>
#include "buffer.h"
#include <vector>

namespace graphics {

class VertexArray {
    private:
    GLuint array_id;
    std::vector<Buffer*> buffers;
    
    public:
    VertexArray();
    ~VertexArray();
    void add_buffer(Buffer* buffer, GLuint index);
    void bind() const;
    void unbind() const;
};

};
