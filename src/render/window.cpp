#include <iostream>
#include <glad/glad.h>

#include "engine/render/window.h"
#include "engine/scenes/editor_scene.h"

Window::Window() : 
	window(nullptr) {
	std::cout << "window" << std::endl;
}

Window& Window::get() {
	static Window instance;
	return instance;
}

void Window::run(unsigned int w, unsigned int h, const char* t) {
	width = w;
	height = h;
	title = t;

	init();
	update();
}

void Window::change_scene(int scene) {
	delete current_scene;
	switch(scene) {
	case 0:
		current_scene = new EditorScene();
		current_scene->init();
	}
}

void Window::init() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();

	change_scene(0);
}

void Window::update() {
	while (!glfwWindowShouldClose(window)) {
		current_scene->update();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}