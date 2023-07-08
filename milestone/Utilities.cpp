// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 8 July 2023
//
// Citation: 
//   In extractToken(), I was reminded of the idea of using find and substr by chatGPT. 
#include <sstream>
#include <iostream>
#include "Utilities.h"

namespace sdds {

	char Utilities::m_delimiter = '\0';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		size_t start = next_pos;
		size_t end = str.find(m_delimiter, next_pos); //search range includes str[next_pos]
		std::string result{};

		if (end == start) { //if next one is also delimiter or {'a', "a"} case
			more = false;
			throw "   ERROR: No token.\n";
		}
		else if (end == std::string::npos) { //no matches found <- ('b', "a") case
			end = str.length();
			start = end;

			if (end == start) { //rest case's last word
				more = false;
				result = str.substr(next_pos);
				if (getFieldWidth() < result.length()) setFieldWidth(result.length());
				result = trim(result);
			}
		}
		else {
			next_pos = end + 1; //move one step next
			result = str.substr(start, end - start);
			if (getFieldWidth() < result.length()) setFieldWidth(result.length());
			result = trim(result);
		}
		return result;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

	std::string trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
}


