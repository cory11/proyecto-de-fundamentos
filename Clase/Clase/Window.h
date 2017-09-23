#pragma once
#include <string>
#include <SDL\SDL.h>
#include <gl\glew.h>

using namespace std;


enum WindowFlags {
	INVISIBLE =0X1,
	FULLSCREEN =0X2,
	BORDERLES=0X4

};


class Window
{
private:
	SDL_Window *_window;
	int _screenWidth;
	int _screenHeight;
public:
	Window();
	~Window();

	void swapWindow();

	int getScreenWidth() {
		return _screenWidth;
	}

	int getScreenHeight() {
		return _screenHeight;
	}

	int create(string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
};

