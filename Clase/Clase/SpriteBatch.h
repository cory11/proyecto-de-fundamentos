#pragma once
#include <gl\glew.h>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <vector>


enum class GlyphShortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE

};

struct Glyph {
	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
};

class RenderBatch {
	RenderBatch(GLuint offset,
		GLuint numVertixes,
		GLuint texture);
	GLuint _offset;
	GLuint _numVertixes;
	GLuint _texture;

};


class SpriteBatch
{
private:
	GLuint _vbo;
	GLuint _vao;

	std::vector<Glyph*> _glpyhs;
	std::is_move_constructible<RenderBatch> _renderBatches;
	void createVertexArray();
	void sortGlyph();
	GlyphShortType _sortType;
	void createRenderbatches();
public:
	
	SpriteBatch();
	~SpriteBatch();

	void init();
	void begin(GlyphShortType sortType = GlyphShortType::TEXTURE);
	void end();
	void draw();
	void renderBatch();
};

