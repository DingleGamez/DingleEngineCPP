#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "engine/render/renderer.h"

Renderer::Renderer(Camera* c, Scene* s)
	: scene(s), camera(c), shader("res/shaders/default_vertex.glsl", "res/shaders/default_fragment.glsl") {};

void Renderer::init() {
	glEnable(GL_DEPTH_TEST);

	shader.attach();

	camera->adjust_projection(800, 600);

	shader.upload_mat4("projection", camera->get_projection());
}

//float yPos = 0.0f;

void Renderer::update() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//yPos += 0.01f;

	shader.attach();

	shader.upload_mat4("view", camera->get_view());

	for (Mesh* mesh : scene->meshes) {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, mesh->position);
		model = glm::rotate(model, glm::radians(mesh->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(mesh->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(mesh->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, mesh->scale);

		shader.upload_mat4("model", model);

		mesh->draw();
	}
}