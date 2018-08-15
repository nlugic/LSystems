#ifndef LSYSTEMRENDERER_H
#define LSYSTEMRENDERER_H

#ifdef LSYSTEMRENDERER_EXPORTS
#define LSYSTEMRENDERER_API __declspec(dllexport)
#else
#define LSYSTEMRENDERER_API __declspec(dllimport)
#endif

namespace LSystemRendererAPI
{

	class LSystemRenderer
	{
	public:
		static LSYSTEMRENDERER_API void test();
	};

}

#endif
