#pragma once
#include <SDL/SDL.h>
#include <glew/glew.h>
#include "Sprite.h"
#include "GLS_Program.h"
#include "Window.h"
#include <vector>
#include "Camera2D.h"
#include "InputManager.h"
#include "SpriteBatch.h"
#include "Human.h"
#include "Zombie.h"
#include "Level.h"
#include "Player.h"


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
	//vector<Sprite*> _sprites;
	Camera2D _camera2D;
	InputManager _inputManager;
	GLS_Program _program;

	vector<Level*> _levels;
	vector<Human*> _humans;
	vector<Zombie*> _zombies;
	Player* _player;
	SpriteBatch _spriteBacth;
	int _currentLevel;


	

	void initShaders();
	//SDL_Window* _window;

	
	void processInput();
	void handleInput();
	const float CAMERA_SPEED = 0.05f;
	const float SCALE_SPEED = 0.1f;

public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void run();
	void draw();
	void update();
};

