#pragma once
#include "GL Texture.h"
#include <map>
class TextureCache
{
	std::map < std::string, GL_Texture> _textureMap;
public:
	TextureCache();
	~TextureCache();

	GL_Texture getTexture(std::string texturePath);
};

