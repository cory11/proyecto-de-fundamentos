#pragma once
#include <glew/glew.h>
#include <string>
#include "GL Texture.h"
using namespace std;
class Sprite
{
private:
	int _width;
	int _height;
	float _x;
	float _y;
	GLuint _vobID;
	GL_Texture _texture;
public:
	Sprite();
	~Sprite();
	void init(float x, float y, int width, int height,
				string texturePath);
	void draw();
};

