#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/render/window.h"

int main() {
	Window& window = Window::get();
	window.run(800, 600, "Dingle Engine C++");

	return 0;
}