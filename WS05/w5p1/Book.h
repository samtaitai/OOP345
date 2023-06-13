#pragma once
#include <string>
#include <iostream>

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
		Book(const std::string& strBook);
		Book(const Book& Ro);
		Book& operator= (const Book& Ro);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		std::ostream& display(std::ostream& os) const;
		std::string trim(std::string& str);
		Book& setPrice(double newPrice);
	};
	std::ostream& operator<<(std::ostream& os, const Book& Ro);
}


