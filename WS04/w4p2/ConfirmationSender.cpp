/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 6 June 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include "ConfirmationSender.h"
#include "Restaurant.h"

using namespace std;
namespace sdds {
	ostream& operator<<(std::ostream& os, ConfirmationSender& Ro)
	{
		return Ro.display(os);
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_ppReservations;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& Ro)
	{
		*this = Ro;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& Ro)
	{
		if (this != &Ro) {
			delete[] m_ppReservations;
			m_ppReservations = new const Reservation * [Ro.size()];
			for (int i = 0; i < Ro.size(); i++) {
				m_ppReservations[i] = Ro.m_ppReservations[i];
			}
			m_cnt = Ro.m_cnt;
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& Ro) noexcept
	{
		*this = std::move(Ro);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& Ro) noexcept
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
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		/*
		if the address of res is already in the array, this operator does nothing
		resizes the array to make room for res if necessary
		stores the address of res in the array (your function should not make copies of the reservation itself)
		*/
		bool found{};
		for (int i = 0; i < m_cnt; i++) {
			if (m_ppReservations[i] == &res) found = true;
		}

		if (!found) {
			const Reservation** temp{};
			temp = new const Reservation * [m_cnt + 1];
			
			for (int i = 0; i < m_cnt; i++) {
				temp[i] = m_ppReservations[i];
			}
			temp[m_cnt] = &res;

			m_cnt++;
			delete[] m_ppReservations;
			m_ppReservations = new const Reservation * [m_cnt];

			for (int i = 0; i < m_cnt; i++) {
				m_ppReservations[i] = temp[i];
			}
			delete[] temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		/*
		To challenge yourself, try to actually resize the array. <- ???
		*/

		for (int i = 0; i < m_cnt; i++) {
			if (m_ppReservations[i] == &res) {
				m_ppReservations[i] = nullptr;
			}
		}
		return *this;
	}
	size_t ConfirmationSender::size() const
	{
		return m_cnt;
	}
	ostream& ConfirmationSender::display(std::ostream& os) const
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (m_cnt == 0) {
			os << "There are no confirmations to send!" << endl;
		}
		else {
			for (int i = 0; i < m_cnt; i++) {
				if(m_ppReservations[i] != nullptr) m_ppReservations[i]->display(os);
			}
		}
		os << "--------------------------" << endl;
		return os;
	}
}
