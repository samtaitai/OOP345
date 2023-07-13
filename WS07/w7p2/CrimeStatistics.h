/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 7 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include <string>
#include <vector>
#include <iostream>
#include <list>
#pragma once

namespace sdds {

	struct Crime {
		std::string province{};
		std::string district{};
		std::string crime{};
		unsigned int year{};
		unsigned int numOfCases{};
		unsigned int m_resolved{};
		Crime& operator=(const char* cstring);
	};
	class CrimeStatistics
	{
		std::vector<Crime> statistics;

	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const;
		void sort(const char* filter);
		void cleanList();
		bool inCollection(const char* crime) const;
		std::list<Crime> getListForProvince(const char* province) const;
	};

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
	std::string trim(std::string& str);
	

}

