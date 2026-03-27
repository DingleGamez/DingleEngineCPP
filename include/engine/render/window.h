#pragma once

#include <GLFW/glfw3.h>
#include <string>

#include "engine/scenes/scene.h"

class Window {
public:
	static Window& get();

	void run(unsigned int w, unsigned int h, const char* t);
	void change_scene(int scene);

	Scene* current_scene;
private:
	void init();
	void frames();
	void update();

	unsigned int width;
	unsigned int height;
	const char* title;
	float start_time = glfwGetTime();
	unsigned int frame_count = 0;

	GLFWwindow* window;

	Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
};
	