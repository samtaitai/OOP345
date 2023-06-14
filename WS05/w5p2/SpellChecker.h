#pragma once
#include <string>
#include <iostream>

namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		static int count[6];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out);
	};
}


