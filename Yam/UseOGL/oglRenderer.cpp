#include "PrecompH.h"
#include "oglRenderer.h"
#include "GmWin.h"
#include "glad/glad.h"

namespace Yam
{
	void oglRenderer::Draw(Yam::Sprite& pic, int x, int y, int z, Yam::Shader shader)
	{
		int width{ GmWin::GetWindow()->GetWidth() };
		int height{ GmWin::GetWindow()->GetHeight() };
		
		shader.Bind();
		pic.Bind();
		
		shader.Set2IntUni("windowSize", width, height);
		shader.Set3IntUni("spriteCoord", x, y, z);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void oglRenderer::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}