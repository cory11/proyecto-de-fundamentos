#pragma once
#include <unordered_map>
#include <glm\glm.hpp>

class InputManager
{

private:
	std::unordered_map<unsigned int, bool> _keys;
	glm::vec2 _mouseCoords;

public:
	InputManager();
	glm::vec2  mouseCoords() {
		return _mouseCoords;
	}

	void setMouseCoords(float x, float y);
	void pressKey(unsigned int KeyCode);
	void releaseKey(unsigned int KeyCode);
	bool isKeyPressed(unsigned int KeyCode);

	~InputManager();
};

