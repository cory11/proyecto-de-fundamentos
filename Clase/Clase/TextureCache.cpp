#include "TextureCache.h"
#include "ImageLoader.h"


TextureCache::TextureCache()
{
}

GL_Texture TextureCache::getTexture(std::string TexturePath) {
	std::map<std::string, GL_Texture>::iterator mit;
	mit = _textureMap.find(TexturePath);

	//auto textures=textureMap.find(TexturePath);


	if (mit == _textureMap.end()) {
		GL_Texture texture = ImageLoader::loadPNG(TexturePath);
		_textureMap[TexturePath] = texture;
		return texture;
	}
	return mit->second;
}


TextureCache::~TextureCache()
{
}
