#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "engine/entities/camera.h"

Camera::Camera(glm::vec3 p) :
	position(p), yaw(-90.0f), pitch(0.0f),
	camera_front(glm::vec3(0.0f, 0.0f, -1.0f)),
	camera_right(glm::vec3(1.0f)), camera_up(glm::vec3(0.0f, 1.0f, 0.0f)) {}

void Camera::adjust_projection(unsigned int width, unsigned int height) {
	projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 0.1f, 1000.0f);
}

glm::mat4 Camera::get_view() {
	glm::vec3 front = glm::vec3(0.0f);
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	camera_front = glm::normalize(front);

	camera_right = glm::normalize(glm::cross(camera_front, glm::vec3(0.0f, 1.0f, 0.0f)));
	camera_up = glm::normalize(glm::cross(camera_right, camera_front));

	view = glm::lookAt(position, camera_front + position, camera_up);
	return view;
}

glm::mat4 Camera::get_projection() {
	return projection;
}