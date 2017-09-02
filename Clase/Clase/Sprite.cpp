#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>

Sprite::Sprite()
{
	_vobID = 0;
}





void Sprite::init(int width, int height,
					float x,float y) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (_vobID == 0) {
		glGenBuffers(1, &_vobID);
	}
	Vertex vertexdata[6];
	vertexdata[0].setPosition(_x + _width, _y + _height);
	vertexdata[1].setPosition(_x, _y+_height);
	vertexdata[2].setPosition(_x, _y);
	vertexdata[3].setPosition(_x, _y);
	vertexdata[4].setPosition(_x+_width, _y);
	vertexdata[5].setPosition(_x+_width, _y+_height);

	glBindBuffer(GL_ARRAY_BUFFER, _vobID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexdata), vertexdata, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}


void Sprite::draw() {
	glBindBuffer(GL_ARRAY_BUFFER, _vobID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
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