#include "ResourceManager.h"



TextureCache ResourceManager :: _textureCache;

GL_Texture ResourceManager::getTexture(std::string texturePath) {
	return _textureCache.getTexture(texturePath);
}