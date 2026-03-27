#pragma once

#include <glm/glm.hpp>

class Shader {
public:
    Shader(const char* vertex_path, const char* fragment_path);

    int compile();
    void attach();
    void detach();
    void upload_mat4(const std::string& name, const glm::mat4& mat);
    void upload_vec3(const std::string& name, const glm::vec3& vec);
    void upload_vec3(const std::string& name, float x, float y, float z);
    void upload_texture(const std::string& name, int value);

private:
    std::string load_file(const char* path);
    unsigned int compile_shader(unsigned int type, const char* source);

    unsigned int shader_program;
};