#include "Agent.h"
#include "ResourceManager.h"


Agent::Agent()
{
}

bool Agent::collideWithLevel(const std::vector<std::string>& levelData) {
	return true;
}

void Agent::checkTilePosition(
	const std::vector<std::string> &levelData,
	std::vector<glm::vec2>& collideTilePosition,
	float x, float y) {

}

void Agent::collideWithTile(glm::vec2 tilePos) {

}

bool Agent::collideWithAgent(Agent* agent) {
	return false;
}

void Agent::draw(SpriteBacth& spriteBatch) {
	static int textureID = ResourceManager::getTexture("Textures/circle.png").id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, AGENT_WIDTH, AGENT_WIDTH);
	spriteBatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

Agent::~Agent()
{
}
