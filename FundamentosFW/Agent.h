#pragma once
#include <glm\glm.hpp>
#include "SpriteBatch.h"
#include "GLTexture.h"

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS 
    = AGENT_WIDTH / 2.0f;

class Zombie;
class Human;

class Agent
{
protected:
	glm::vec2 _position;
	float _speed;
	Color color;
	void checkTilePosition(
		const std::vector<std::string> &levelData,
		std::vector<glm::vec2>& collideTilePosition,
		float x, float y);
	void collideWithTile(glm::vec2 tilePos);
public:
	Agent();
	glm::vec2 getPosition()const {
		return _position;
	}
	virtual void update(
		const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies
	) = 0;
	void draw(SpriteBacth& SpriteBatch);
	bool collideWithLevel(
		const std::vector<std::string>& levelData);
	bool collideWithAgent(Agent* agent);
	virtual ~Agent();
};

