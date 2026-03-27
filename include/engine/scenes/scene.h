#pragma once

#include <vector>

#include "engine/render/mesh.h"

class Scene {
public:
	Scene() { std::cout << "gay" << std::endl; };

	virtual void init() {};
	virtual void update() {};

	std::vector<Mesh*>meshes;
};