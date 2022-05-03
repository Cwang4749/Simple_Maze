#include "PrecompH.h"
#include "oglShader.h"
#include "glad/glad.h"

namespace Yam
{
	oglShader::oglShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Read File
		std::string srcCode;
		std::ifstream vertexInput{ vertexFile };
		
		while (vertexInput)
		{
			std::string line;
			std::getline(vertexInput, line);
			line.append("\n");
			srcCode += line;
		}

		vertexInput.close();

		const char* cSrc = srcCode.c_str();

		glShaderSource(vertexShader, 1, &cSrc, NULL);
		glCompileShader(vertexShader);

		//check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Read File
		srcCode.clear();
		std::ifstream fragmentInput{ fragmentFile };

		while (fragmentInput)
		{
			std::string line;
			std::getline(fragmentInput, line);
			line.append("\n");
			srcCode += line;
		}

		fragmentInput.close();

		const char* fragSrc = srcCode.c_str();

		glShaderSource(fragmentShader, 1, &fragSrc, NULL);
		glCompileShader(fragmentShader);

		//check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		//link shaders
		mShaderID = glCreateProgram();
		glAttachShader(mShaderID, vertexShader);
		glAttachShader(mShaderID, fragmentShader);
		glLinkProgram(mShaderID);
		//check for linking errors
		glGetProgramiv(mShaderID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::Program::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	void oglShader::Set3IntUni(const std::string& uniName, int uni1, int uni2, int uni3)
	{
		int uniLoc{ glGetUniformLocation(mShaderID, uniName.c_str()) };
		glUseProgram(mShaderID);
		glUniform3i(uniLoc, uni1, uni2, uni3);
	}
	void oglShader::Set2IntUni(const std::string& uniName, int uni1, int uni2)
	{
		int uniLoc{ glGetUniformLocation(mShaderID, uniName.c_str()) };
		glUseProgram(mShaderID);
		glUniform2i(uniLoc, uni1, uni2);
	}
	void oglShader::Bind()
	{
		glUseProgram(mShaderID);
	}
}