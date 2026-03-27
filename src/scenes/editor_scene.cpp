#include <iostream>

#include "engine/scenes/editor_scene.h"

EditorScene::EditorScene() : camera(glm::vec3(0.0f)) {
	std::cout << "Scene" << std::endl;
	renderer = new Renderer(&camera, this);
};

void EditorScene::init() {
	std::cout << "Scene init" << std::endl;

	Mesh* cube = new Mesh();
	cube->init();
	meshes.push_back(cube);

	renderer->init();
}

void EditorScene::update() {
	meshes[0]->rotation.z += 1.0f;
	meshes[0]->position.z += 0.025f;

	renderer->update();
}

