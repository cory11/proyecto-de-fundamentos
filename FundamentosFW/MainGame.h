#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include "Window.h"
#include <vector>
#include "Camera2D.h"
#include "InputManager.h"
#include "SpriteBatch.h"
#include "Human.h"
#include "Zombie.h"
#include "Player.h"
#include "Level.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	//SDL_Window* _window;
	void init();
	//vector<Sprite*> _sprites;
	Camera2D _camera2D;
	InputManager _inputManager;
	Window _window;
	GLS_Program _program;
	float _time;
	void processInput();
	vector<Level*> _levels;
	vector<Human*> _humans;
	vector<Zombie*> _zombies;
	SpriteBacth _spriteBacth;
	int _currentLevel;
	Player* _player;

	void handleInput();
	const float CAMERA_SPEED = 0.05f;
	const float SCALE_SPEED = 0.01f;

public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

