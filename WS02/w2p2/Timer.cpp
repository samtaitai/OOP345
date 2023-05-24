/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 24 May 2023
* Citation:
* start/stop function logic is assisted.
* source: https://cplusplus.com/reference/chrono/duration/duration/
* https://stackoverflow.com/questions/57538507/how-to-convert-stdchronoduration-to-double-seconds
*/
#include "Timer.h"

namespace sdds {

	void Timer::start()
	{
		auto start = std::chrono::steady_clock::now();
		m_timestamp = start;
	}
	long long Timer::stop()
	{
		long long result;
		//# of ticks is represented in long long & tick period is nanoseconds 
		typedef std::chrono::duration<long long, std::ratio<1, 1000000000>> nanoseconds_type;
		
		auto end = std::chrono::steady_clock::now();
		nanoseconds_type diff = end - m_timestamp;
		result = diff.count();
		return result;
	}
}
