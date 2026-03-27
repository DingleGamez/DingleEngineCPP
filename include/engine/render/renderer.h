#pragma once

#include "engine/render/shader.h"
#include "engine/scenes/scene.h"
#include "engine/entities/camera.h"

class Renderer {
public:
	Renderer(Camera* camera, Scene* scene);

	void init();
	void update();
private:
	Shader shader;
	Scene* scene;
	Camera* camera;
};