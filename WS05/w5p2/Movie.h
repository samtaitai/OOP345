#pragma once
#include <string>
#include <iostream>

namespace sdds {
	class Movie
	{
		std::string m_title{};
		int m_year{};
		std::string m_desc{};

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker);
		std::ostream& display(std::ostream& os);
	};
	std::ostream& operator<< (std::ostream & os, Movie & Ro);
}


