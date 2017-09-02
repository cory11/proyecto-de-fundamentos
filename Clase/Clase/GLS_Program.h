#pragma once
#include <glew/glew.h>
#include <string>

using namespace std;

class GLS_Program
{
private:
	GLuint _fragmentShaderID;
	GLuint _vertexShaderID;
	GLuint _programID;
	
	void compileShader(const string& sharepath, GLuint id);
public:
	GLS_Program();
	~GLS_Program();
	int _numAttribute;

	void compileShaders(const string& vertexShaderPath, const string& fragmentShaderPath);

	void linkShader();

	void addAttribute(const string atributeName);
	void use();
	void unuse();

	GLuint getUniformLocation(const string &name);
};

