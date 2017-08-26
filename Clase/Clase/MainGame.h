#pragma once
#include <SDL/SDL.h>
enum class GameState {

	PLAY, EXIT
};
class MainGame
{
private:
	int _width;
	int _height;
	void init();
	SDL_Window* _window;
	void processInput();
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void run();
	void draw();
	void update();
};

