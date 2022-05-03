#pragma once

#include "ShaderImplementation.h"

namespace Yam
{
	class oglShader : public ShaderImplementation
	{
	public:
		oglShader(const std::string& vertexFile, const std::string& fragmentFile);
		
		virtual void Set3IntUni(const std::string& uniName, int uni1, int uni2, int uni3) override;
		virtual void Set2IntUni(const std::string& uniName, int uni1, int uni2) override;
		virtual void Bind() override;

	private:
		unsigned int mShaderID;

	};
}

