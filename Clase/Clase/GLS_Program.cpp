#include "GLS_Program.h"
#include <fstream>
#include <vector>

void GLS_Program::compileShader(const string& shaderpath, GLuint id) {
	string fileContent = "";
	string line = "";
	ifstream shaderFile(shaderpath);
	if (shaderFile.fail()) {}

	while (getline(shaderFile, line)) {
		fileContent += line + "/n";
	}
	shaderFile.close();
	const char* contents = fileContent.c_str();
	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);

	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(id); // Don't leak the shader.
		return;
	}
}

void GLS_Program::compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath) {
	_programID = glCreateProgram();

	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0){

	}
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (_fragmentShaderID == 0) {

	}

	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);

}

void GLS_Program::linkShader() {

}

GLS_Program::GLS_Program(): _programID(0), _fragmentShaderID(0),_vertexShaderID(0)
{
}


GLS_Program::~GLS_Program()
{
}
