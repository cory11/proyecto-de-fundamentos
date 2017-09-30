#include "ImageLoader.h"
#include "IOManager.h"
#include <vector>
#include "Error.h"
#include "picoPNG.h"

GLTexture ImageLoader::loadPNG(string filePath) {
	GLTexture texture = {};

	vector<unsigned char>in;
	vector<unsigned char>out;
	unsigned long width, height;

	if (!IOManager::readFileToBuffer(filePath,in)) {
		fatalError("Could not read file " + filePath);
	}
	int errorCode = decodePNG(out, width, height, 
								&(in[0]), in.size());

	if (errorCode != 0) {
		fatalError("Cant' decode image with error " 
						+ to_string(errorCode));
	}

	glGenTextures(1, &(texture.id));
	glBindTexture(GL_TEXTURE_2D, texture.id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
						GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE, 0);
	texture.width = width;
	texture.height = height;
	return texture;







}
