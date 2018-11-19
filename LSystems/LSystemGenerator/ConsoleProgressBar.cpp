
#include "ConsoleProgressBar.h"
#include <iostream>
#include <string>

namespace lsysh
{

	ConsoleProgressBar::ConsoleProgressBar(size_t units, unsigned markers, const char *logPath)
		:progress(0.0f), progressIncrement(100.0f / units), markerCount(markers), progressMarker(0.0f),
			start(std::chrono::steady_clock::now()), log(logPath, std::ios::app) { }

	float ConsoleProgressBar::getProgress() const
	{
		return progress;
	}

	void ConsoleProgressBar::step()
	{
		progress += progressIncrement;
		progressMarker = std::floorf(progress / (100.0f / markerCount));
		if (std::floorf(progress) - std::floorf(progress - progressIncrement) > epsilon)
			std::cout << "\r[" << std::string(static_cast<unsigned>(progressMarker), '#')
			<< std::string(markerCount - static_cast<unsigned>(progressMarker), ' ') << "] [" << std::floorf(progress) << "%]";
	}

	void ConsoleProgressBar::finish(bool newLine)
	{
		progress = 100.0f;
		progressMarker = static_cast<float>(markerCount);
		std::cout << "\r[" << std::string(markerCount, '#') << "] [100%]" << std::endl;
		end = std::chrono::steady_clock::now();
		float executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0f;
		std::cout << "Operation took " << executionTime << " seconds." << std::endl;
		if (newLine)
			log << std::ceil(100.0f / progressIncrement) << ',';
		log << executionTime << ((newLine) ? '\n' : ',');
		log.close();
	}

	void ConsoleProgressBar::reset()
	{
		progress = 0.0f;
		progressMarker = 0.0f;
	}

}
