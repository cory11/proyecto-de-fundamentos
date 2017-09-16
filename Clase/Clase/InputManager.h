#pragma once
#include <unordered_map>

class InputManager
{

private:
	std::unordered_map<unsigned int, bool> _keys;


public:
	InputManager();

	void pressKey(unsigned int KeyCode);
	void releaseKey(unsigned int KeyCode);
	void isKeyPressed(unsigned int KeyCode);

	~InputManager();
};

