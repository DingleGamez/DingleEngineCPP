#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "engine/render/shader.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 tex_coords;
};

struct Texture {
	unsigned int id;
	std::string path;
};

class Mesh {
public:
	std::vector<Vertex>vertices;
	std::vector<unsigned int>indices;
	std::vector<Texture>textures;

	Mesh(std::vector<Vertex>vertices, std::vector<unsigned int>indices, std::vector<Texture>textures);

	unsigned int vao;

	void draw(Shader& shader);
private:
	unsigned int vbo;
	unsigned int ebo;

	void setup_mesh();
};