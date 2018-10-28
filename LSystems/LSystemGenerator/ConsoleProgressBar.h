#ifndef CONSOLEPROGRESSBAR_H
#define CONSOLEPROGRESSBAR_H

namespace lsysh
{

	const float epsilon = 1e-5f;

	class ConsoleProgressBar
	{
	private:
		float progress, progressIncrement;
		unsigned markerCount;
		float progressMarker;

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
