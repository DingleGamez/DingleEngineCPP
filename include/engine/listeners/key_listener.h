#pragma once

#include <GLFW/glfw3.h>
#include <vector>

class KeyListener {
public:
	static KeyListener& get();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	bool is_key_pressed(int key);
private:
	KeyListener();

	std::vector<bool> key_pressed;

	KeyListener(const KeyListener&) = delete;
	KeyListener& operator=(const KeyListener&) = delete;
};