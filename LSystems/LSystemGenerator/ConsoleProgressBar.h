
#include "GlobalDefinitions.h"

#if !defined(CONSOLEPROGRESSBAR_H) && (defined(_DEBUG) || defined(_VERBOSE))
#define CONSOLEPROGRESSBAR_H

#include <fstream>
#include <chrono>

namespace lhelp
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
		explicit inline ConsoleProgressBar(std::size_t units, unsigned int markers = 25u,
			const char *log_path = "./benchmark.csv")
			:marker_count(markers), progress(0.0f), progress_increment(100.0f / units), progress_marker(0.0f),
			start(std::chrono::steady_clock::now()), log(log_path, std::ios::app) { }
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
