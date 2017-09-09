#include "MainGame.h"
#include <iostream>
#include "Error.h"
using namespace std;


MainGame::MainGame() : _window(nullptr), _width(800), _height(800), _gameState(GameState::PLAY), _time(0)
{
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL);


	if (_window == nullptr) {
		fatalError("SDL_Window was not loaded");
	}


	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	GLenum error = glewInit();

	if (error != GLEW_OK) {
		fatalError("GLEW was not loaded");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
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
	_time += 0.0002;

	GLuint imageLocation = _program.getUniformLocation("image");
	glUniform1i(imageLocation, _time);

	for (size_t i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}
	//_sprite.draw();
	_program.unuse();

	//draw elements
	SDL_GL_SwapWindow(_window);
}

void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
			case SDL_MOUSEMOTION:
				cout << "x:"<< event.motion.x << "y:"<< event.motion.y << endl;

				break;
		}
	}
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
