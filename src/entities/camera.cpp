#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "engine/entities/camera.h"

Camera::Camera(glm::vec3 p) {
	position = p;
}

void Camera::adjust_projection(unsigned int width, unsigned int height) {
	projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 0.1f, 1000.0f);
}

glm::mat4 Camera::get_view() {
	glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
	view = glm::lookAt(glm::vec3(position.x, position.y, 10.0f), camera_front + position, camera_up);
	return view;
}

glm::mat4 Camera::get_projection() {
	return projection;
}