/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 24 May 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#pragma once
#include <chrono>
#include <ctime>
#include <iostream>

namespace sdds {
	class Timer
	{
		std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> m_timestamp;
	public:
		void start();
		long long stop();
	};
}


