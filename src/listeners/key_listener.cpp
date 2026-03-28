#include <iostream>

#include "engine/listeners/key_listener.h"

KeyListener::KeyListener() :
	key_pressed(GLFW_KEY_LAST, false)
{
};

KeyListener& KeyListener::get() {
	static KeyListener instance;
	return instance;
}

void KeyListener::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	KeyListener& instance = KeyListener::get();

	if (key < instance.key_pressed.size()) {
		if (action == GLFW_PRESS) {
			instance.key_pressed[key] = true;
		}
		else if (action == GLFW_RELEASE) {
			instance.key_pressed[key] = false;
		}
	}
}

bool KeyListener::is_key_pressed(int key) {
	if (key < key_pressed.size()) {
		return key_pressed[key];
	}
	return false;
}