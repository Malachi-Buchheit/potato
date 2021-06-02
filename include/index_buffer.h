#pragma once
#include </usr/include/GL/glew.h>

namespace graphics {

class IndexBuffer {
    private:
    GLuint buffer_id, 
           count;
    
    public:
    IndexBuffer(GLushort *data, GLsizei count);
    ~IndexBuffer();
    
    void bind() const;
    void unbind() const;

    inline GLuint getCount() const {return count;}
};

};

