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
		size_t end = str.find(m_delimiter, next_pos);
		std::string result{};

		if (end == start) {
			more = false;
			throw "   ERROR: No token.\n";
		}
		else if (end == std::string::npos) {
			end = str.length();
			start = end;

			if (end == start) {
				more = false;
				//throw "   ERROR: No token.\n";
				result = str.substr(next_pos);
				if (getFieldWidth() < result.length()) setFieldWidth(result.length());
				return trim(result);
			}

		}
		else {

			
			next_pos = end + 1;
			
			result = str.substr(start, end - start);
			if (getFieldWidth() < result.length()) setFieldWidth(result.length());
			return trim(result);
		}
		

		

		//std::string result{};
		//std::string temp = str.substr(next_pos);
		//std::stringstream row(temp);
		//std::string newStr{};

		////"apple,orange,banana,kiwi,strawberry,yellow watermellon"

		//if (row.peek() == m_delimiter) { //Hello ll situation
		//	more = false;
		//	throw "   ERROR: No token.\n";
		//}
		//else {
		//	std::getline(row, result, m_delimiter);
		//	if (result.length() > 0) {
		//		result = trim(result);
		//		next_pos = next_pos + result.length();
		//		if (getFieldWidth() < result.length()) setFieldWidth(result.length());
		//		if (!temp[next_pos]) more = false;
		//		return result;
		//	}
		//	else more = false;
		//	
		//}
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


