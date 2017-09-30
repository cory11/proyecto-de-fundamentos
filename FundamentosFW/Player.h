#pragma once
#include "Human.h"
#include <glm\glm.hpp>

class Player : public Human
{
public:
	Player();
	~Player();
	void init(float speed,glm::vec2 position);
	void update();
};

