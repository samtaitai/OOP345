#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book(const std::string& strBook)
	{
		size_t idxC = strBook.find(',');
		size_t idxC1 = strBook.find(',', idxC + 1);
		size_t idxC2 = strBook.find(',', idxC1 + 1);
		size_t idxC3 = strBook.find(',', idxC2 + 1);
		size_t idxC4 = strBook.find(',', idxC3 + 1);

		m_author = strBook.substr(0, idxC);
		m_author = this->trim(m_author);
		m_title = strBook.substr(idxC + 1, (idxC1 - idxC - 1));
		m_title = this->trim(m_title);
		m_country = strBook.substr(idxC1 + 1, (idxC2 - idxC1 - 1));
		m_country = this->trim(m_country);
		m_price = stod(strBook.substr(idxC2 + 1, (idxC3 - idxC2 - 1)));
		m_year = stoi(strBook.substr(idxC3 + 1, (idxC4 - idxC3 - 1)));
		m_desc = strBook.substr(idxC4 + 1);
		m_desc = this->trim(m_desc);
	}
	Book::Book(const Book& Ro)
	{
		*this = Ro;
	}
	Book& Book::operator=(const Book& Ro)
	{
		if (this != &Ro) {
			m_author = Ro.m_author;
			m_title = Ro.m_title;
			m_country = Ro.m_country;
			m_year = Ro.m_year;
			m_price = Ro.m_price;
			m_desc = Ro.m_desc;
		}
		return *this;
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	std::ostream& Book::display(std::ostream& os) const
	{
		os.width(20);
		os << m_author;
		os << " | ";
		os.width(22);
		os << m_title;
		os << " | ";
		os.width(5);
		os << m_country;
		os << " | ";
		os.width(4);
		os << m_year;
		os << " | ";
		os.width(6);
		os.setf(ios::fixed);
		os.precision(2);
		os << m_price;
		os << " | ";
		os << m_desc << endl;

		return os;
	}
	std::string Book::trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
	Book& Book::setPrice(double newPrice)
	{
		m_price = newPrice;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Book& Ro)
	{
		return Ro.display(os);
	}
}
