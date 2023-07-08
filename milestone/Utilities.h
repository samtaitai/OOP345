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


