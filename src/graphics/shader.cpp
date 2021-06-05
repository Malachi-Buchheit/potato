#include "shader.h"
#include <vector>

using namespace graphics;

Shader::Shader(const char* vert_path, const char* frag_path)
    : m_vert_path(vert_path), m_frag_path(frag_path) {
    shader_id = load();
}

Shader::~Shader() {
    glDeleteProgram(shader_id);
}

GLuint Shader::load() {
    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vert_string = read_file(m_vert_path);
    std::string frag_string = read_file(m_frag_path);

    const char* vert_source = vert_string.c_str();
    const char* frag_source = frag_string.c_str();

    GLint result;

    glShaderSource(vertex, 1, &vert_source, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE) {
        GLint length;
        glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(vertex, length, &length, &error[0]);
        std::cout << "ERROR: Failed to construct vertex shader\n" << &error[0] << std::endl;
        glDeleteShader(vertex);
        return 0;
    }

    glShaderSource(fragment, 1, &frag_source, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE) {
        GLint length;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(fragment, length, &length, &error[0]);
        std::cout << "ERROR: Failed to construct fragment shader\n" << &error[0] << std::endl;
        glDeleteShader(fragment);
        return 0;
    }

    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glValidateProgram(program);

    glDetachShader(program, vertex);
    glDetachShader(program, fragment);
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return program;
}

void Shader::enable() const {
    glUseProgram(shader_id);
}

void Shader::disable() const {
    glUseProgram(0);
}

void Shader::setUniform1f(const GLchar* name, float f) {
    glUniform1f(getUniformLocation(name), f);
}

void Shader::setUniform1i(const GLchar* name, int i) {
    glUniform1i(getUniformLocation(name), i);
}

void Shader::setUniform2f(const GLchar* name, math::vec2 v) {
    glUniform2f(getUniformLocation(name), v.x, v.y);
}

void Shader::setUniform3f(const GLchar* name, math::vec3 v) {
    glUniform3f(getUniformLocation(name), v.x, v.y, v.z);
}

void Shader::setUniform4f(const GLchar* name, math::vec4 v) {
    glUniform4f(getUniformLocation(name), v.x, v.y, v.z, v.w);
}

void Shader::setUniformMat4(const GLchar* name, math::mat4 m) {
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, m.elem);
}

GLint Shader::getUniformLocation(const GLchar* name) {
    return glGetUniformLocation(shader_id, name);
}
