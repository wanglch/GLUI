#pragma once

#include <GLUI/Utils.h>
#include <GLUI/Layout.h>

namespace glui {
	typedef void(*glpanel_render_func)(void);
	typedef void(*glpanel_init_gl_func)(void);

	struct GLFuncs;

	class GLPanel : public GLUIObject {
	private:
		unsigned int m_FBO;
		unsigned int m_tex;
		unsigned int m_dtex;
		unsigned int m_glInitList;
		glpanel_render_func m_renderFunc;
		glpanel_init_gl_func m_initGLFunc;

		GLFuncs* m_glFuncs;

		Vector2f m_fboSize;
	public:
		GLPanel(Rectangle bounds, Vector2f fboSize, Layout* layout, glpanel_init_gl_func initGLFunc, glpanel_render_func renderFunc);
		void poll() override;
		void render() override;
		void renderDepth();
	};
}