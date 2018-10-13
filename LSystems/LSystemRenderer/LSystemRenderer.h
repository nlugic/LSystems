#ifndef LSYSTEMRENDERER_H
#define LSYSTEMRENDERER_H

#include "..\LSystemGenerator\LSystemContext.h"
#include "OGLRenderer.h"

#ifdef LSYSTEMRENDERER_EXPORTS
#define LSYSTEMRENDERER_API __declspec(dllexport)
#else
#define LSYSTEMRENDERER_API __declspec(dllimport)
#endif

namespace lrend
{

	class LSystemRenderer
	{
	private:
		lsys::LSystemContext *current;

		LSystemRenderer(lsys::LSystemContext *lCxt);
		LSystemRenderer(const LSystemRenderer&) = delete;
		LSystemRenderer& operator=(const LSystemRenderer&) = delete;

	public:
		~LSystemRenderer();

		static LSYSTEMRENDERER_API void testOGLRender();
		static LSYSTEMRENDERER_API void testTurtleRender();
	};

}

#endif
