#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

namespace sdds {
	Restaurant::Restaurant(const Reservation** reservations, size_t cnt)
	{
		Reservation* temp = nullptr;
		temp = new Reservation[cnt];

		for (int i = 0; i < cnt; i++) {
			temp[i] = *(reservations[i]);
		}

		m_ppReservations = new Reservation* [cnt];
		for (int i = 0; i < cnt; i++) {
			
			m_ppReservations[i] = &temp[i]; //expect copy constructor
		}
		//delete[] temp;
	}

	Restaurant::~Restaurant()
	{
		delete[] m_ppReservations;
	}

	Restaurant::Restaurant(const Restaurant& Ro)
	{
		*this = Ro;
	}

	Restaurant& Restaurant::operator=(const Restaurant& Ro)
	{
		m_ppReservations = nullptr;
		m_cnt = 0;

		if (this != &Ro) {
			delete[] m_ppReservations;
			m_ppReservations = new Reservation*[Ro.size()];
			for (int i = 0; i < Ro.size(); i++) {
				m_ppReservations[i] = Ro.m_ppReservations[i];
			}
			m_cnt = Ro.m_cnt;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& Ro) noexcept
	{
		*this = std::move(Ro);
	}

	Restaurant& Restaurant::operator=(Restaurant&& Ro) noexcept
	{
		if (this != &Ro) {
			delete[] m_ppReservations;
			m_ppReservations = Ro.m_ppReservations;
			m_cnt = Ro.m_cnt;
			Ro.m_ppReservations = nullptr;
			Ro.m_cnt = 0;
		}
		return *this;
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
				m_ppReservations[i]->display(os);
			}
		}
		os << "--------------------------" << endl;
		return os;
	}

	Reservation* Restaurant::operator[](size_t idx) const
	{
		if (m_cnt < idx) return nullptr;
		else {
			return m_ppReservations[idx];
		}
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& Ro)
	{
		getCalled++;
		return Ro.display(os);
	}
}


