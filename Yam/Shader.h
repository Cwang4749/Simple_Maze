#pragma once

#include "ShaderImplementation.h"
#include "YamUtility.h"

namespace Yam {
	class YAM_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		void Set3IntUni(const std::string& uniName, int uni1, int uni2, int uni3);
		void Set2IntUni(const std::string& uniName, int uni1, int uni2);
		void Bind();
	
	private:
		ShaderImplementation* mImplementation;
	};
}
