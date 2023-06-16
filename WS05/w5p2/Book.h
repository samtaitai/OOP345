/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 12 June 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#pragma once
#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace sdds {
	class Book
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_desc{};

	public:
		Book() = default;
		~Book() = default;
		Book(const std::string& strBook);
		Book(const Book& Ro);
		Book& operator= (const Book& Ro);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();//
		std::ostream& display(std::ostream& os) const;
		std::string& trim(std::string& str);
		//Book& setPrice(double newPrice);//price
		template <typename T>
		void fixSpelling(T& spellChecker);
	};
	std::ostream& operator<<(std::ostream& os, const Book& Ro);
	template<typename T>
	inline void Book::fixSpelling(T& spellChecker)
	{
		spellChecker(Book::m_desc);
	}
}


