#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "engine/render/renderer.h"
#include "engine/entities/model.h"

Renderer::Renderer(Camera* c, Scene* s)
	: scene(s), camera(c), shader("res/shaders/default_vertex.glsl", "res/shaders/default_fragment.glsl") {};

void Renderer::init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	shader.attach();

	camera->adjust_projection(1280, 720);

	shader.upload_mat4("projection", camera->get_projection());
}

void Renderer::update() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.attach();

	shader.upload_mat4("view", camera->get_view());
	shader.upload_vec3("lightPos", glm::vec3(0.0f,1.0f,2.0f));
	shader.upload_vec3("lightColor", 1.0, 1.0, 1.0);

	for (Model* model : scene->models) {
		glm::mat4 mat = glm::mat4(1.0f);
		mat = glm::translate(mat, model->position);
		mat = glm::rotate(mat, glm::radians(model->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		mat = glm::rotate(mat, glm::radians(model->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		mat = glm::rotate(mat, glm::radians(model->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		mat = glm::scale(mat, model->scale);

		shader.upload_mat4("model", mat);

		model->draw(shader);
	}
}