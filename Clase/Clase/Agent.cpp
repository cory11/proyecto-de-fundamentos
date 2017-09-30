#include "Agent.h"
#include "ResourceManager.h"


Agent::Agent()
{
}

bool Agent::collidedeWithLevel(const std::vector<std::string>& levelData) { return false; }

void Agent::checkTilePosition(const std::vector<std::string>&levelData, std::vector<glm::vec2>& collideTilePosition, float x, float y) {

}

void Agent::collideWithTile(glm::vec2 tilePos) {}

void Agent::draw(SpriteBatch& SpriteBatch) {
	static int textureID = ResourceManager::getTexture("Textures/circle.png").id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, AGENT_WIDTH, AGENT_WIDTH);
	SpriteBatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

Agent::~Agent()
{
}
