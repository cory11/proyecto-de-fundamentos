#pragma once
#include <string>
#include <SDL\SDL.h>
#include <gl\glew.h>

using namespace std;

enum WindowFlags {
	INVISBLE = 0x1,
	FULLSCREEN = 0x2,
	BORDERLES = 0x4
};

class Window
{
private:
	SDL_Window *_window;
	int _screenWidth;
	int _screenHeigth;
public:
	Window();
	~Window();
	void swapWindow();
	int getScreenWidth() 
	{ 
		return _screenWidth; 
	}
	int getScreenHeight() 
	{
		return _screenHeigth;
	}
	int create(string windowName,
		int screenWidth,
		int screenHeight,
		unsigned int currentFlags
	);
};

