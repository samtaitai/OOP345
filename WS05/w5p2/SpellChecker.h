/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 16 June 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#pragma once
#include <string>
#include <iostream>

namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[6];
		std::string m_goodWords[6];
		static int count[6];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out);
	};
}


