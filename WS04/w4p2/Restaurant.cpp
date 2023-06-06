#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_reservations = new Reservation * [cnt];
		for (int i = 0; i < cnt; i++) {
			
			*(m_reservations[i]) = *(reservations[i]); //expect copy constructor
		}
	}

	Restaurant::~Restaurant()
	{
		delete[] m_reservations;
	}

	size_t Restaurant::size() const
	{
		return m_cnt;
	}

	std::ostream& Restaurant::display(std::ostream& os) const
	{
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << getCalled << ')' << endl;
		os << "--------------------------" << endl;
		if (getCalled == 0) {
			os << "This restaurant is empty!" << endl;
		}
		else {
			for (int i = 0; i < m_cnt; i++) {
				m_reservations[i]->display(os);
			}
		}
		os << "--------------------------" << endl;
		return os;
	}

	Reservation* Restaurant::operator[](size_t idx) const
	{
		if (m_cnt < idx) return nullptr;
		else {
			return m_reservations[idx];
		}
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& Ro)
	{
		getCalled++;
		return Ro.display(os);
	}
}


