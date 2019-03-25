
#include "GlobalDefinitions.h"

#if !defined(CONSOLEPROGRESSBAR_H) && (defined(_DEBUG) || defined(_VERBOSE))
#define CONSOLEPROGRESSBAR_H

#include <fstream>
#include <chrono>

namespace lsysh
{

	const float epsilon = 1e-5f;

	class ConsoleProgressBar
	{
	private:
		float progress, progressIncrement;
		unsigned markerCount;
		float progressMarker;

		std::chrono::steady_clock::time_point start, end;
		std::ofstream log;

	public:
		ConsoleProgressBar(std::size_t units, unsigned markers = 25U, const char *logPath = "./benchmark.csv");
		ConsoleProgressBar(const ConsoleProgressBar&) = delete;
		ConsoleProgressBar& operator=(const ConsoleProgressBar&) = delete;

		float getProgress() const;
		void step();
		void finish(bool newLine = false);
		void reset();
	};

}

#endif
