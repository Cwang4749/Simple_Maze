#include "PrecompH.h"
#include "Shader.h"
#include "UseOGL/oglShader.h"

namespace Yam
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef YAM_OPENGL
		mImplementation = new oglShader(vertexFile, fragmentFile);
#else
		#ONLY_OPENGL_SUPPORTED_FOR_NOW
#endif
	}
	void Shader::Set3IntUni(const std::string& uniName, int uni1, int uni2, int uni3)
	{
		mImplementation->Set3IntUni(uniName, uni1, uni2, uni3);
	}
	void Shader::Set2IntUni(const std::string& uniName, int uni1, int uni2)
	{
		mImplementation->Set2IntUni(uniName, uni1, uni2);
	}
}