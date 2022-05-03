#pragma once

namespace Yam
{
	class ShaderImplementation {
	public:
		virtual void Set3IntUni(const std::string& uniName, int uni1, int uni2, int uni3) = 0;
		virtual void Set2IntUni(const std::string& uniName, int uni1, int uni2) = 0;
		virtual void Bind() = 0;
	};
}