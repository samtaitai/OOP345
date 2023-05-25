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
		m_timestamp = std::chrono::steady_clock::now();
	}
	long long Timer::stop()
	{
		//1. convert (end-start) to duration by duration cast
		//2. convert 1. to long long by .count() 
		long long result;
		//# of ticks is represented in long long & tick period is nanoseconds 
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_timestamp);
		long long totalTime = duration.count();
		return totalTime;
		/*
		auto end = std::chrono::steady_clock::now();
		nanoseconds_type diff = end - m_timestamp;
		*/

		//return # of ticks(in type it is represented == long long?) 
		//result = diff.count();
		//return result;
	}
}
