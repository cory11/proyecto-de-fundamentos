#include "Level.h"
#include "ResourceManager.h"
#include <fstream>


Level::Level(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
		
	}
	std::string tmp;
	file >> tmp >> _numHumas;

	while (std::getline(file,tmp)) {
		_levelData.push_back(tmp);
	}
	parseLevel();
}


void Level::parseLevel() {
	_spriteBatch.init();
	_spriteBatch.begin();
	Color color;
	color.set(255, 255, 255, 255);
	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	for (size_t y = 0; y < _levelData.size(); y++)
	{
		for (size_t x = 0; x < _levelData[y].size(); x++)
		{
			char tile = _levelData[y][x];
			glm::vec4 destRect(
				x*TITLE_WIDTH, y*TITLE_WIDTH,
				TITLE_WIDTH, TITLE_WIDTH);
			switch (tile)
			{
			case 'R':
			case 'B':
				_spriteBatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/red_bricks.png").id,
					0.0f, color);
				break;
			case 'G':
				_spriteBatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/red_bricks.png").id,
					0.0f, color);
				break;
			case 'L':
				_spriteBatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/red_bricks.png").id,
					0.0f, color);
				break;
			case '@':
				_levelData[y][x] = '.';
				_playerPosition.x = x*TITLE_WIDTH;
				_playerPosition.y = y*TITLE_WIDTH;
				break;
			case'Z':
				_levelData[y][x] = '.';
				_zombiesPosition.emplace_back(x*TITLE_WIDTH, y*TITLE_WIDTH);
				break;
			case '.':
				break;
			default:
				break;
			}
		}
	}
	_spriteBatch.end();
}


void Level::draw() {
	_spriteBatch.renderBatch();
}

Level::~Level()
{
}
