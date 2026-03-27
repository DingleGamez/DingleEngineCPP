#pragma once

#include <glm/glm.hpp>

class Camera {
public:
	Camera(glm::vec3 p);

	glm::vec3 position;

	void adjust_projection(unsigned int width, unsigned int height);
	glm::mat4 get_view();
	glm::mat4 get_projection();
private:
	glm::mat4 view;
	glm::mat4 projection;
};