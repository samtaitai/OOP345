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
		delete[] m_pReservations;
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
			for (int j = 0; j < m_pReservations[i].size(); j++) {
				if(m_pReservations[i][j] == &res) found = true; 
			}
		}

		if (!found) {
			//resize
			//store res
		}
		return *this;
	}
	ostream& ConfirmationSender::display(std::ostream& os)
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (m_cnt == 0) {
			os << "There are no confirmations to send!" << endl;
		}
		else {
			for (int i = 0; i < m_cnt; i++) {
				//m_pReservations[i] array of Restaurant*
				for (int j = 0; j < m_pReservations[i].size(); j++) {
					m_pReservations[i].display(os);
				}
			}
		}
		return os;
	}
}
