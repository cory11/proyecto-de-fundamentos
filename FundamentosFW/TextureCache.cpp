#include "TextureCache.h"
#include "ImageLoader.h"


TextureCache::TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath) {
	//std::map<std::string, GLTexture>::iterator mit;
	//mit = _textureMap.find(texturePath);

	auto textures = _textureMap.find(texturePath);
	if (textures == _textureMap.end()) {
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		_textureMap[texturePath] = texture;
		return texture;
	}
	return textures->second;
}


TextureCache::~TextureCache()
{
}
