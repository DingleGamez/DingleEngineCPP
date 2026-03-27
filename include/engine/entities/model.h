#pragma once

#include <glm/glm.hpp>
#include <assimp/scene.h>
#include <vector>

#include "engine/render/mesh.h"
#include "engine/render/shader.h"

class Model {
public:
	Model(const std::string& path);

	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 rotation = glm::vec3(0.0f);
	glm::vec3 scale = glm::vec3(1.0f);

	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;

	void draw(Shader& shader);
private:
	void load_model(const std::string& path);
	void process_node(aiNode* node, const aiScene* scene);
	Mesh process_mesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> load_material_textures(aiMaterial* mat, aiTextureType type, std::string typeName);
};