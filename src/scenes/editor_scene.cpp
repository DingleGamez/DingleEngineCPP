#include <iostream>

#include "engine/scenes/editor_scene.h"

EditorScene::EditorScene() : camera(glm::vec3(0.0f)) {
	std::cout << "Scene" << std::endl;
	renderer = new Renderer(&camera, this);
};

void EditorScene::init() {
	std::cout << "Scene init" << std::endl;

	Model* city = new Model("res/models/city/scene.gltf");
	models.push_back(city);

	Model* backpack = new Model("res/models/backpack/backpack.obj");
	models.push_back(backpack);

	renderer->init();
}

void EditorScene::update() {
	models[0]->rotation.y += 0.1f;

	renderer->update();
}

