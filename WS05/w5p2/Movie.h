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
	class Movie
	{
		std::string m_title{};
		int m_year{};
		std::string m_desc{};

	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker);
		std::ostream& display(std::ostream& os) const;
		std::string& trim(std::string& str);
		friend std::ostream& operator<< (std::ostream& os, const Movie& Ro);
	};
	template<typename T>
	inline void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(Movie::m_title);
		spellChecker(Movie::m_desc);
	}
}


