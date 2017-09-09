#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>
#include <string>
#include "ResourceManager.h"

using namespace std;
Sprite::Sprite()
{
	_vobID = 0;
}





void Sprite::init(int width, int height,float x,float y, string texturePath)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	

	if (_vobID == 0) {
		glGenBuffers(1, &_vobID);
	}
	_texture = ResourceManager::getTexture(texturePath);


	Vertex vertexdata[6];

	vertexdata[0].setUV(1.0f, 1.0f);
	vertexdata[1].setUV(0.0f, 1.0f);
	vertexdata[2].setUV(0.0f, 0.0f);
	vertexdata[3].setUV(0.0f, 0.0f);
	vertexdata[4].setUV(1.0f, 0.0f);
	vertexdata[5].setUV(1.0f, 1.0f);

	vertexdata[0].setPosition(_x + _width, _y + _height);
	vertexdata[1].setPosition(_x, _y + _height);
	vertexdata[2].setPosition(_x, _y);
	vertexdata[3].setPosition(_x, _y);
	vertexdata[4].setPosition(_x + _width, _y);
	vertexdata[5].setPosition(_x + _width, _y+ _height);

	for (int i = 0; i < 6; i++)
	{
		vertexdata[i].setColor(255, 0, 0, 255);
	}
	vertexdata[1].setColor(0, 0, 255, 255);
	vertexdata[3].setColor(0, 255, 0, 255);


	glBindBuffer(GL_ARRAY_BUFFER, _vobID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexdata), vertexdata, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}


void Sprite::draw() {
	glBindTexture(GL_TEXTURE_2D, _texture.id);
	glBindBuffer(GL_ARRAY_BUFFER, _vobID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	//segundo atributo color
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	//tercer atributo color
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}


Sprite::~Sprite()
{
	if (_vobID != 0) {
		glDeleteBuffers(1, &_vobID);
	}
}