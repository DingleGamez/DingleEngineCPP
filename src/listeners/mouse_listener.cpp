#include <iostream>

#include "engine/listeners/mouse_listener.h"

MouseListener::MouseListener()
	: mouse_button_pressed(8, false) {

}

MouseListener& MouseListener::get() {
	static MouseListener instance;
	return instance;
}

void MouseListener::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	MouseListener& instance = MouseListener::get();

	if (button < instance.mouse_button_pressed.size()) {
		if (action == GLFW_PRESS) {
			instance.mouse_button_pressed[button] = true;
		}
		else if (action == GLFW_RELEASE) {
			instance.mouse_button_pressed[button] = false;
		}
	}
};

bool MouseListener::mouse_button_down(int button) {
	if (button < mouse_button_pressed.size()) {
		return mouse_button_pressed[button];
	}
	return false;
}