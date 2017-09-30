#include "SpriteBatch.h"
#include <algorithm>


SpriteBatch::SpriteBatch(): _vbo(0), _vao(0)
{

}


void SpriteBatch::init() {
	createVertexArray();

}

void SpriteBatch::draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color) {
	Glyph* glyph = new Glyph;
	glyph->texture = texture;
	glyph->depth = depth;

	glyph->topLeft.color = color;
	glyph->topLeft.setPosition(destRect.x, destRect.y + destRect.w);
	glyph->topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
	
	glyph->bottomLeft.color = color;
	glyph->bottomLeft.setPosition(destRect.x, destRect.y );
	glyph->bottomLeft.setUV(uvRect.x, uvRect.y);

	glyph->bottomRight.color = color;
	glyph->bottomRight.setPosition(destRect.x + destRect.z, destRect.y );
	glyph->bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

	glyph->topRight.color = color;
	glyph->topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
	glyph->topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);

	_glyphs.push_back(glyph);
}

void SpriteBatch::createVertexArray() {
	if (_vao == 0) {
		glGenVertexArrays(1, &_vao);
	}

	glBindVertexArray(_vao);

	if (_vbo == 0) {
		glGenBuffers(1, &_vbo);
	}

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	//segundo atributo color
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	//tercer atributo color
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void SpriteBatch::begin(GlyphSortType sortType) {
	_sortType = sortType;
	_renderBatches.clear();
	for (size_t i = 0; i < _glyphs.size(); i++)
	{
		delete _glyphs[i];
	}

	_glyphs.clear();
}

void SpriteBatch::createRenderbatches() {
	std::vector<Vertex> vertices;
	vertices.resize(_glyphs.size() * 6);
	if (_glyphs.empty()) {

		return;
	}

	int cv = 0;
	int ofset = 0;

	_renderBatches.emplace_back(ofset, 6, _glyphs[0]->texture);
	vertices[cv++] = _glyphs[0]->topLeft;
	vertices[cv++] = _glyphs[0]->bottomLeft;
	vertices[cv++] = _glyphs[0]->bottomRight;
	vertices[cv++] = _glyphs[0]->bottomRight;
	vertices[cv++] = _glyphs[0]->topRight;
	vertices[cv++] = _glyphs[0]->topLeft;
	ofset += 6;

	for (size_t i = 1; i < _glyphs.size(); i++)
	{
		if (_glyphs[i]->texture != _glyphs[i-1]->texture) {
			_renderBatches.emplace_back(ofset, 6, _glyphs[i]->texture);
		}
		else {
			_renderBatches.back()._numVertixes += 6;
		}
		vertices[cv++] = _glyphs[i]->topLeft;
		vertices[cv++] = _glyphs[i]->bottomLeft;
		vertices[cv++] = _glyphs[i]->bottomRight;
		vertices[cv++] = _glyphs[i]->bottomRight;
		vertices[cv++] = _glyphs[i]->topRight;
		vertices[cv++] = _glyphs[i]->topLeft;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),nullptr, GL_DYNAMIC_DRAW );
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size()*sizeof(Vertex), vertices.data());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SpriteBatch::renderBatch() {
	glBindVertexArray(_vao);
	for (size_t i = 0; i < _renderBatches.size(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, _renderBatches[i]._texture);
		glDrawArrays(GL_TRIANGLES, _renderBatches[i]._offset, _renderBatches[i]._numVertixes);

	}
	glBindVertexArray(0);
}

void SpriteBatch::end() {
	sortGlyph();
	createRenderbatches();
}

void SpriteBatch::sortGlyph() {
	switch (_sortType)
	{
	case GlyphSortType::BACK_TO_FRONT:
		std::stable_sort( _glyphs.begin(), _glyphs.end(), compareBackToFront);
		break;
	case GlyphSortType::FRONT_TO_BACK:
		std::stable_sort(_glyphs.begin(), _glyphs.end(), compareFrontToBack);
		break;
	case GlyphSortType::TEXTURE:
		std::stable_sort(_glyphs.begin(), _glyphs.end(), compareTexture);
		break;
	case GlyphSortType::NONE:
		break;
	}
}

bool SpriteBatch::compareBackToFront(Glyph* a, Glyph*b) {
	return (a->depth < b->depth);
}

bool SpriteBatch::compareFrontToBack(Glyph* a, Glyph*b) {
	return (a->depth > b->depth);
}

bool SpriteBatch::compareTexture(Glyph* a, Glyph*b) {
	return (a->texture < b->texture);
}




RenderBatch::RenderBatch(GLuint offset, GLuint numVertixes, GLuint texture) {

}

SpriteBatch::~SpriteBatch()
{
}
