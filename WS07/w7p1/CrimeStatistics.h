#include <string>
#include <vector>
#include <iostream>
#pragma once

namespace sdds {

	struct Crime {
		std::string province{};
		std::string district{};
		std::string crime{};
		unsigned int year{};
		unsigned int numOfCases{};
		unsigned int numOfresolved{};
	};
	class CrimeStatistics
	{
		std::vector<Crime> statistics;

	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const;
	};

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
	std::string trim(std::string& str);

}

