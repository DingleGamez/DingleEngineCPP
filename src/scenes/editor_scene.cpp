#include <iostream>

#include "engine/scenes/editor_scene.h"
#include "engine/listeners/mouse_listener.h"
#include "engine/listeners/key_listener.h"

EditorScene::EditorScene() : camera(glm::vec3(0.0f, 0.0f, 10.0f)) {
	std::cout << "Scene" << std::endl;
	renderer = new Renderer(&camera, this);
};

void EditorScene::init() {
	std::cout << "Scene init" << std::endl;

	Model* city = new Model("res/models/city/scene.gltf");
	models.push_back(city);

	//Model* backpack = new Model("res/models/backpack/backpack.obj");
	//models.push_back(backpack);

	renderer->init();
}

void EditorScene::update(float dt) {
	//std::cout << MouseListener::get().mouse_button_down(GLFW_MOUSE_BUTTON_1) << std::endl;
	//std::cout << KeyListener::get().is_key_pressed(GLFW_KEY_SPACE) << std::endl;
	//std::cout << dt << std::endl;

	float turn_speed = 75.0f;
	float move_speed = 30.0f;

	KeyListener& kl_instance = KeyListener::get();

	if (kl_instance.is_key_pressed(GLFW_KEY_LEFT)) {
		camera.yaw -= turn_speed * dt;
	}
	if (kl_instance.is_key_pressed(GLFW_KEY_RIGHT)) {
		camera.yaw += turn_speed * dt;
	}
	if (kl_instance.is_key_pressed(GLFW_KEY_UP)) {
		camera.pitch += turn_speed * dt;
	}
	if (kl_instance.is_key_pressed(GLFW_KEY_DOWN)) {
		camera.pitch -= turn_speed * dt;
	}

	if (kl_instance.is_key_pressed(GLFW_KEY_A)) {
		camera.position -= camera.camera_right * move_speed * dt;
	}
	if (kl_instance.is_key_pressed(GLFW_KEY_D)) {
		camera.position += camera.camera_right * move_speed * dt;
	}
	if (kl_instance.is_key_pressed(GLFW_KEY_W)) {
		camera.position += camera.camera_front * move_speed * dt;
	}
	if (kl_instance.is_key_pressed(GLFW_KEY_S)) {
		camera.position -= camera.camera_front * move_speed * dt;
	}

	renderer->update();
}

