#ifndef LSYSTEMGENERATOR_H
#define LSYSTEMGENERATOR_H

#ifdef LSYSTEMGENERATOR_EXPORTS
#define LSYSTEMGENERATOR_API __declspec(dllexport)
#else
#define LSYSTEMGENERATOR_API __declspec(dllimport)
#endif

namespace LSystemGeneratorAPI
{

	class LSystemGenerator
	{
	public:
		static LSYSTEMGENERATOR_API void testLSystem();
	};

}

#endif
