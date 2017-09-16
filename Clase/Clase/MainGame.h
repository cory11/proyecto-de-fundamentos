#pragma once
#include <SDL/SDL.h>
#include <glew/glew.h>
#include "Sprite.h"
#include "GLS_Program.h"
#include "Window.h"
#include <vector>
using namespace std;
enum class GameState {

	PLAY, EXIT
};
class MainGame
{
private:
	int _width;
	int _height;
	float _time;
	Window _window;
	//Sprite _sprite;
	void init();
	vector<Sprite*> _sprites;
	GLS_Program _program;
	void initShaders();
	//SDL_Window* _window;
	void processInput();
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void run();
	void draw();
	void update();
};

