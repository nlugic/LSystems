
#include "ConsoleProgressBar.h"

#if defined(_DEBUG) || defined(_VERBOSE)

#include <iostream>
#include <string>

namespace lsysh
{

	ConsoleProgressBar::ConsoleProgressBar(std::size_t units, unsigned int markers, const char *log_path)
		:marker_count(markers), progress(0.0f), progress_increment(100.0f / units), progress_marker(0.0f),
			start(std::chrono::steady_clock::now()), log(log_path, std::ios::app) { }

	float ConsoleProgressBar::getProgress() const { return progress; }

	void ConsoleProgressBar::step()
	{
		progress += progress_increment;
		progress_marker = std::floorf(progress / (100.0f / marker_count));
		if (std::floorf(progress) - std::floorf(progress - progress_increment) > eps)
			std::clog << "\r[" << std::string(static_cast<unsigned int>(progress_marker), '#')
			<< std::string(marker_count - static_cast<unsigned int>(progress_marker), ' ') << "] ["
			<< std::floorf(progress) << "%]";
	}

	void ConsoleProgressBar::finish(bool new_line)
	{
		progress = 100.0f;
		progress_marker = static_cast<float>(marker_count);
		std::clog << "\r[" << std::string(marker_count, '#') << "] [100%]" << std::endl;
		end = std::chrono::steady_clock::now();
		float execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0f;
		std::clog << "Operation took " << execution_time << " seconds." << std::endl;
		if (new_line)
			log << std::ceil(100.0f / progress_increment) << ',';
		log << execution_time << ((new_line) ? '\n' : ',');
		log.close();
	}

	void ConsoleProgressBar::reset() { progress = progress_marker = 0.0f; }

}

#endif
