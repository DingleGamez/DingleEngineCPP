#pragma once

#include <GLFW/glfw3.h>
#include <vector>

class MouseListener {
public:
	static MouseListener& get();

	void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
	void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	bool mouse_button_down(int button);
private:
	MouseListener();

	double scrollX; double scrollY;
	double mouseX; double mouseY;
	double lastX; double lastY;
	std::vector<bool> mouse_button_pressed;
	bool is_dragging;

	MouseListener(const MouseListener&) = delete;
	MouseListener& operator=(const MouseListener&) = delete;
};