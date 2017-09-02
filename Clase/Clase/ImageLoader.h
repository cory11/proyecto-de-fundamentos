#pragma once
#include "GL Texture.h"
#include <string>

using namespace std;

class ImageLoader
{
public:
	static GL_Texture loadPNG(string filePath);
};

