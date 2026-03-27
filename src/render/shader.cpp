#include <iostream>
#include <glad/glad.h>
#include <fstream>
#include <sstream>

#include "engine/render/shader.h"

Shader::Shader(const char* vertex_path, const char* fragment_path) {
    std::string vertex_shader_source = load_file(vertex_path);
    std::string fragment_shader_source = load_file(fragment_path);

    unsigned int vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex_shader_source.c_str());
    unsigned int fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fragment_shader_source.c_str());

    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    //glBindAttribLocation(shader_program, 0, "position");
    glLinkProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    int success;
    char info_log[512];

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);
        std::cout << "Shader Program Linking Error:\n" << info_log << std::endl;
    }
}

std::string Shader::load_file(const char* path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cout << "FAILED TO LOAD: " << path << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

unsigned int Shader::compile_shader(unsigned int type, const char* source) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    char info_log[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cout << "Shader Compile Error:\n" << info_log << std::endl;
    }

    return shader;
}

void Shader::upload_mat4(const std::string& name, const glm::mat4& mat) {
    glUniformMatrix4fv(glGetUniformLocation(shader_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::upload_vec3(const std::string& name, const glm::vec3& value) {
    glUniform3fv(glGetUniformLocation(shader_program, name.c_str()), 1, &value[0]);
}

void Shader::upload_vec3(const std::string& name, float x, float y, float z) {
    glUniform3f(glGetUniformLocation(shader_program, name.c_str()), x, y, z);
}

void Shader::upload_texture(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(shader_program, name.c_str()), value);
}

void Shader::attach() {
    glUseProgram(shader_program);
}

void Shader::detach() {
    glUseProgram(0);
}