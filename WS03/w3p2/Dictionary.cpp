/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 30 May 2023
* Citation:
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include "Dictionary.h"

using namespace std;

namespace sdds {
	Dictionary::Dictionary()
	{
		m_term = "";
		m_definition = "";
	}

	ostream& Dictionary::display(std::ostream& os) const
	{
		os.width(20);
		os << m_term;
		os << ": "; 
		os.setf(ios::left);
		os << m_definition;
		os.unsetf(ios::left);
		return os; 

	}
	bool Dictionary::operator==(Dictionary& Ro)
	{
		return m_term.compare(Ro.m_term) == 0 && m_definition.compare(Ro.m_definition) == 0;
	}
	std::ostream& operator<<(std::ostream& os, const Dictionary& Ro)
	{
		return Ro.display(os);
	}
}