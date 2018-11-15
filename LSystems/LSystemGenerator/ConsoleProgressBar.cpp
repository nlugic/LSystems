
#include "ConsoleProgressBar.h"
#include <iostream>
#include <string>

namespace lsysh
{

	ConsoleProgressBar::ConsoleProgressBar(size_t units, unsigned markers)
		:progress(0.0f), progressIncrement(100.0f / units), markerCount(markers), progressMarker(0.0f),
			start(std::chrono::steady_clock::now()) { }

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

	void ConsoleProgressBar::finish()
	{
		progress = 100.0f;
		progressMarker = static_cast<float>(markerCount);
		std::cout << "\r[" << std::string(markerCount, '#') << "] [100%]" << std::endl;
		end = std::chrono::steady_clock::now();
		std::cout << "Operation took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0f
			<< " seconds." << std::endl;
	}

	void ConsoleProgressBar::reset()
	{
		progress = 0.0f;
		progressMarker = 0.0f;
	}

}
