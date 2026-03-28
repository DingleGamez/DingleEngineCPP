#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/render/window.h"

int main() {
	Window& window = Window::get();
	window.run(1280, 720, "Dingle Engine C++");

	return 0;
}