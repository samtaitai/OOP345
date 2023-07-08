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
		std::string result{};
		std::stringstream row(str);

		if (str[next_pos] == m_delimiter) { //Hello ll situation
			more = false;
			throw "   ERROR: No token.\n";
		}
		else {
			std::getline(row, result, m_delimiter);
			result = trim(result);
			next_pos++;
			if (getFieldWidth() < result.length()) setFieldWidth(result.length());
			if (!str[next_pos]) more = false;
			return result;
		}
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


