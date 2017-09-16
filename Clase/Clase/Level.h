#pragma once
#include <vector>
#include <string>
#include "SpriteBatch.h"
#include <glm\glm.hpp>

using namespace std;
const int TITTLE_WIDTH = 64;

class Level
{
private:
	vector<string> _levelData;
	int _numHumas;
	void parseLevel();
	
public:

	glm::vec2 _playerPosition;
	std::vector <glm::vec2> _zombiePosition;
	glm::vec2 getPplayerPosition() const{
		return _playerPosition;
	};
	std::vector<glm::vec2> getZombiesPosition() const {
		return _zombiePosition;
	};

	Level(const std::string& fileName);
	void draw();
	SpriteBatch _spriteBatch;

	~Level();
};

