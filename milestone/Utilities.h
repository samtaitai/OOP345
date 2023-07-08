// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 8 July 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#pragma once

namespace sdds {
	class Utilities
	{
		size_t m_widthField{};
		static char m_delimiter;

	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();

	};

	//helper
	std::string trim(std::string& str);
}


