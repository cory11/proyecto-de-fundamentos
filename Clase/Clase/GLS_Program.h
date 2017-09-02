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
	int _numAttribute;
	void compileShader(const string& sharepath, GLuint id);
public:
	GLS_Program();
	~GLS_Program();

	void compileShaders(const string& vertexShaderPath, const string& fragmentShaderPath);

	void linkShader();

	void addAttribute();
	void use();
	void unuse();
};

