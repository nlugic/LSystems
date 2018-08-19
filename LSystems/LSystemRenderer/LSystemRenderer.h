#ifndef LSYSTEMRENDERER_H
#define LSYSTEMRENDERER_H

#include "..\LSystemGenerator\LSystem.h"
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
	protected:
		lsys::LSystem *current; // vector?
		OGLRenderer renderer;

	public:
		LSystemRenderer(lsys::LSystem *lSys);
		LSystemRenderer(const LSystemRenderer& lRnd) = delete;
		LSystemRenderer& operator=(const LSystemRenderer& lRnd) = delete;
		virtual ~LSystemRenderer();

		static LSYSTEMRENDERER_API void test();
	};

}

#endif
