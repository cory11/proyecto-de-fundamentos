#include "Level.h"
#include <fstream>



Level::Level(const std::string& fileName)
{
	std::fstream file;
	file.open(fileName);
	if (file.fail()) {
	
	}

	std::string tmp;
	file >> tmp >> _numHumas;

	while (std::getline(file, tmp)) {
		_levelData.push_back(tmp);
	}
	parseLevel();

}

void Level::parseLevel() {
	for (size_t y = 0; y < _levelData.size(); y++)
	{
		for (size_t x = 0; x < _levelData[y].size(); x++)
		{
			char tile = _levelData[y][x];
			switch (tile)
			{
			case 'R':
				break;
			case 'B':
				break;
			case 'G':
				break;
			case 'L':
				break;
			case '@':
				break;
			case 'Z':
				break;
			case '.':
				break;


			default:

				break;
			}
		}

	}
}


Level::~Level()
{
}
