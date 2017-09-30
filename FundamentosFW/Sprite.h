#pragma once
#include <GL\glew.h>
#include "GLTexture.h"
#include <string>
using namespace std;
class Sprite
{
private:
	float _x;
	float _y;
	int _width;
	int _height;
	float vertexData;
	GLTexture _texture;
	GLuint _vobID;
public:
	Sprite();
	~Sprite();
	void init(float x, float y, int width, 
				int height, string texturePath);
	void draw();

	
};

