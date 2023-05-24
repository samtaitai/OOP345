#pragma once
#include <chrono>
#include <ctime>
#include <iostream>

namespace sdds {
	class Timer
	{
		std::chrono::time_point<std::chrono::high_resolution_clock> m_timestamp;
	public:
		void start();
		long long stop();
	};
}


