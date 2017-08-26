#pragma once
#include <glew/glew.h>
class Sprite
{
private:
	int _width;
	int _height;
	float _x;
	float _y;
	GLuint _vobID;
public:
	Sprite();
	~Sprite();
	void init(int width,
				int height,
				float x,
				float y);
	void draw();
};

