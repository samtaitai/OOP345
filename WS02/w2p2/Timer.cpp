/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 24 May 2023
* Citation:
* start/stop function logic is assisted.
* source: https://cplusplus.com/reference/chrono/duration/duration/
* https://cplusplus.com/reference/chrono/duration_cast/
*/
#include "Timer.h"

namespace sdds {

	void Timer::start()
	{
		m_timestamp = std::chrono::steady_clock::now();
	}
	long long Timer::stop()
	{
		//1. convert (end-start) to duration by duration cast
		//2. convert 1. to long long by .count() 
		std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> end = 
			std::chrono::steady_clock::now(); 
		std::chrono::nanoseconds diff = 
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_timestamp);
		long long totalTime = diff.count();
		return totalTime;
	}
}
