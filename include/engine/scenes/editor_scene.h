#pragma once

#include <vector>

#include "engine/render/renderer.h"
#include "engine/render/mesh.h"
#include "engine/scenes/scene.h"
#include "engine/entities/camera.h"

class EditorScene : public Scene {
public:
	EditorScene();

	Camera camera;

	void init() override;
	void update() override;
private:
	Renderer* renderer = nullptr;
};