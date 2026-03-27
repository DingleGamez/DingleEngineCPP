#pragma once

#include <vector>

#include "engine/entities/model.h"

class Scene {
public:
	Scene() {};

	std::vector<Model*>models;

	virtual void init() {};
	virtual void update() {};
};