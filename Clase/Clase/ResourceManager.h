#pragma once
#include "GL Texture.h"
#include "TextureCache.h"
class ResourceManager
{
private:
	static TextureCache _textureCache;

public:
	static GL_Texture getTexture(std::string texturePath);

};

