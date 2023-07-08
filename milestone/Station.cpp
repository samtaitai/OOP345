// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 8 July 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	size_t Station::m_widthField = 0;
	unsigned int Station::id_generator = 0; //should do 

	Station::Station(const std::string& row)
	{
		Utilities util;
		bool more = true;
		size_t pos = 0u;
		try
		{
			Station::id_generator += 1;
			m_id = Station::id_generator;
			m_name = util.extractToken(row, pos, more);
			m_nextSerial = std::stoi(util.extractToken(row, pos, more));
			m_quantity = std::stoi(util.extractToken(row, pos, more));
			Station::m_widthField = util.getFieldWidth();
			m_desc = util.extractToken(row, pos, more);
			
		}
		catch (...) { cout << "   ERROR: No token.\n"; }

	}
	const std::string& Station::getItemName() const
	{
		return m_name;
	}
	size_t Station::getQuantity() const
	{
		return m_quantity;
	}
	void Station::updateQuantity()
	{
		if (m_quantity > 0) m_quantity--;
		else m_quantity = 0;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (full) {
			os.fill('0');
			os.width(3);
			os << m_id;
			os.fill(' ');
			os << " | ";
			os.setf(ios::left);
			os.width(m_widthField);
			os << m_name;
			os << " | ";
			os.fill('0');
			os.unsetf(ios::left);
			os.width(6);
			os << m_nextSerial;
			os.fill(' ');
			os << " | ";
			os.width(4);
			os << m_quantity;
			os << " | ";
			os << m_desc << endl;
		}
		else {
			os.fill('0');
			os.width(3);
			os << m_id;
			os.fill(' ');
			os << " | ";
			os.setf(ios::left);
			os.width(m_widthField);
			os << m_name;
			os << " | ";
			os.fill('0');
			os.unsetf(ios::left);
			os.width(6);
			os << m_nextSerial;
			os.fill(' ');
			os << " | " << endl;
		}
	}
	size_t Station::getNextSerialNumber() const
	{
		return m_nextSerial;
	}
}
