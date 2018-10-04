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
	protected:
		lsys::LSystemContext *current;

	public:
		LSystemRenderer(lsys::LSystemContext *lCxt = nullptr);
		LSystemRenderer(const LSystemRenderer&) = delete;
		LSystemRenderer& operator=(const LSystemRenderer&) = delete;
		~LSystemRenderer();

		static LSYSTEMRENDERER_API void test();
	};

}

#endif
