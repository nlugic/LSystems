
#include "GlobalDefinitions.h"

#if !defined(CONSOLEPROGRESSBAR_H) && (defined(_DEBUG) || defined(_VERBOSE))
#define CONSOLEPROGRESSBAR_H

#include <fstream>
#include <chrono>

namespace lsysh
{

	class ConsoleProgressBar
	{
	private:
		unsigned int marker_count;
		float progress, progress_increment, progress_marker;

		std::chrono::steady_clock::time_point start, end;
		std::ofstream log;

	public:
		ConsoleProgressBar() = delete;
		ConsoleProgressBar(std::size_t units, unsigned int markers = 25U, const char *log_path = "./benchmark.csv");
		ConsoleProgressBar(const ConsoleProgressBar&) = delete;
		ConsoleProgressBar(ConsoleProgressBar&&) = delete;
		ConsoleProgressBar& operator=(const ConsoleProgressBar&) = delete;
		~ConsoleProgressBar() = default;

		inline float getProgress() const { return progress; }
		inline void reset() { progress = progress_marker = 0.0f; }
		void step();
		void finish(bool new_line = false);
	};

}

#endif
