#include "MainGame.h"
#include <iostream>
#include "Error.h"
using namespace std;


MainGame::MainGame() :  _width(800), _height(800), _gameState(GameState::PLAY), _time(0)
{
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	_window.create("Hola :D", _width, _height, 0);
	initShaders();
}

void MainGame::initShaders(){
	_program.compileShaders("Shaders/ColorShaderVert.txt",
		"Shaders/ColorShaderFrag.txt");
	_program.addAttribute("vertexPosition");
	_program.addAttribute("vertexColor");
	_program.addAttribute("vertexUV");
	_program.linkShader();
}

void MainGame::update(){
	while (_gameState != GameState::EXIT) {
		draw();
		_camera2D.update();
		processInput();
	}
}

void MainGame::draw(){
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	_program.use();

	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocation = _program.getUniformLocation("time");
	glUniform1f(timeLocation, _time);
	_time += 0.0002f;

	GLuint imageLocation = _program.getUniformLocation("image");
	glUniform1i(imageLocation, 0);

	for (size_t i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}
	//_sprite.draw();
	_program.unuse();

	//draw elements
	_window.swapWindow();
}

void MainGame::handleInput() {
	if (_inputManager.isKeyPressed(SDLK_w)) {
		_camera2D.setPosition(_camera2D.getPosition() + glm::vec2(0.0, -CAMERA_SPEED));
	}

	if (_inputManager.isKeyPressed(SDLK_s)) {
		_camera2D.setPosition(_camera2D.getPosition() + glm::vec2(0.0, CAMERA_SPEED));
	}

	if (_inputManager.isKeyPressed(SDLK_a)) {
		_camera2D.setPosition(_camera2D.getPosition() + glm::vec2(CAMERA_SPEED, 0.0));
	}

	if (_inputManager.isKeyPressed(SDLK_d)) {
		_camera2D.setPosition(_camera2D.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0));
	}

	if (_inputManager.isKeyPressed(SDLK_q)) {}

	if (_inputManager.isKeyPressed(SDLK_e)) {}

}

void MainGame::processInput() {
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;

			case SDL_MOUSEMOTION:
				_inputManager.setMouseCoords(event.motion.x, event.motion.y);
				break;
			case SDL_KEYDOWN:
				_inputManager.pressKey(event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				_inputManager.releaseKey(event.key.keysym.sym);
				break;
		}
	}
	handleInput();
}

void MainGame::run() {
	init();
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1, -1, 1, 1, "images/imagen.png");
	_sprites.push_back(new Sprite());
	_sprites.back()->init(0, -1, 1, 1, "images/imagen.png");
	//_sprite.init(-1, -1, 1, 1);
	update();	

}


MainGame::~MainGame()
{
}
