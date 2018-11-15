#ifndef CONSOLEPROGRESSBAR_H
#define CONSOLEPROGRESSBAR_H

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

	public:
		ConsoleProgressBar(size_t units, unsigned markers = 25U);
		ConsoleProgressBar(const ConsoleProgressBar&) = delete;
		ConsoleProgressBar& operator=(const ConsoleProgressBar&) = delete;
		~ConsoleProgressBar() = default;

		float getProgress() const;
		void step();
		void finish();
		void reset();
	};

}

#endif
