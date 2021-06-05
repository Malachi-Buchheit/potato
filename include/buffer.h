#pragma once
#include </usr/include/GL/glew.h>

namespace graphics {

class Buffer {
    private:
    GLuint buffer_id, 
           component_count;
    
    public:
    Buffer(GLfloat *data, GLsizei count, GLuint component_count);
    ~Buffer();
    
    void bind() const;
    void unbind() const;

    inline GLuint getComponentCount() const {return component_count;}
};

};

