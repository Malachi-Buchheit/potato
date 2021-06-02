#pragma once
#include "math.h"
#include "fileutils.h"
#include </usr/include/GL/glew.h>
//#include </usr/include/GLFW/glfw3.h>

namespace graphics {

class Shader {
    private:
    GLuint shader_id;
    const char *m_vert_path, *m_frag_path;
    
    public:
    Shader(const char* vert_path, const char* frag_path);
    ~Shader();

    void enable() const;
    void disable() const;

    void setUniform1f(const GLchar* name, float f);
    void setUniform1i(const GLchar* name, int i);
    void setUniform2f(const GLchar* name, math::vec2 v);
    void setUniform3f(const GLchar* name, math::vec3 v);
    void setUniform4f(const GLchar* name, math::vec4 v);
    void setUniformMat4(const GLchar* name, math::mat4 m);

    GLuint get_shader_id() {return shader_id;}

    private: 
    GLuint load();
    GLint getUniformLocation(const GLchar* name);
};

};
