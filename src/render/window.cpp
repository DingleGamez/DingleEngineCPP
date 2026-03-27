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

void Window::frames() {
	frame_count += 1;
	float current_time = glfwGetTime();
	float fps = 0;

	if (current_time - start_time >= 1.0) {
		fps = frame_count / (current_time - start_time);

		std::cout << "FPS: " << fps << std::endl;

		frame_count = 0;
		start_time = current_time;
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
		frames();

		current_scene->update();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}