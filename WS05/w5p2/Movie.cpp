/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 16 June 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include "Movie.h"

using namespace std;

namespace sdds {
    const std::string& Movie::title() const
    {
        return m_title;
    }
    Movie::Movie(const std::string& strMovie)
    {
		size_t idxC = strMovie.find(',');
		size_t idxC1 = strMovie.find(',', idxC + 1);
		//size_t idxC2 = strMovie.find('\n', idxC1 + 1); don't need?

		m_title = strMovie.substr(0, idxC); 
		m_title = this->trim(m_title); 
		m_year = stoi(strMovie.substr(idxC + 1, (idxC1 - idxC - 1)));
		//m_desc = strMovie.substr(idxC1 + 1, (idxC2 - idxC1 - 1));
		m_desc = strMovie.substr(idxC1 + 1);
		m_desc = this->trim(m_desc);
    }
    std::ostream& Movie::display(std::ostream& os) const
    {
		os.width(40);
		os << m_title;
		os << " | ";
		os.width(4);
		os << m_year;
		os << " | ";
		os << m_desc << endl;
		return os;
    }
	std::string& Movie::trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
    std::ostream& operator<<(std::ostream& os, const Movie& Ro)
    {
        return Ro.display(os);
    }
}
