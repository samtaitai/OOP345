#include "ConfirmationSender.h"
#include "Restaurant.h"

using namespace std;
namespace sdds {
	//ostream& operator<<(std::ostream& os, ConfirmationSender& Ro)
	//{
	//	return Ro.display(os);
	//}
	//ConfirmationSender::~ConfirmationSender()
	//{
	//	delete[] m_ppReservations;
	//}
	//ConfirmationSender::ConfirmationSender(const ConfirmationSender& Ro)
	//{
	//	*this = Ro;
	//}
	//ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& Ro)
	//{
	//	if (this != &Ro) {
	//		delete[] m_ppReservations;
	//		for (int i = 0; i < Ro.size(); i++) {
	//			
	//		}
	//	}
	//	return *this;
	//}
	//ConfirmationSender::ConfirmationSender(ConfirmationSender&& Ro)
	//{
	//	*this = std::move(Ro);
	//}
	//ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	//{
	//	/*
	//	if the address of res is already in the array, this operator does nothing
	//	resizes the array to make room for res if necessary
	//	stores the address of res in the array (your function should not make copies of the reservation itself)
	//	*/
	//	bool found{};
	//	for (int i = 0; i < m_cnt; i++) {
	//		for (int j = 0; j < m_ppReservations[i].size(); j++) {
	//			if(m_ppReservations[i][j] == &res) found = true;
	//		}
	//	}

	//	if (!found) {
	//		//resize
	//		
	//		delete[] m_ppReservations;
	//		m_ppReservations = new Restaurant[m_cnt + 1];

	//		//store res
	//	}
	//	return *this;
	//}
	//size_t ConfirmationSender::size() const
	//{
	//	return m_cnt;
	//}
	//ostream& ConfirmationSender::display(std::ostream& os) const
	//{
	//	os << "--------------------------" << endl;
	//	os << "Confirmations to Send" << endl;
	//	os << "--------------------------" << endl;
	//	if (m_cnt == 0) {
	//		os << "There are no confirmations to send!" << endl;
	//	}
	//	else {
	//		for (int i = 0; i < m_cnt; i++) {
	//			//m_ppReservations[i] is array of Restaurant*
	//			for (int j = 0; j < m_ppReservations[i].size(); j++) {
	//				m_ppReservations[i].display(os);
	//			}
	//		}
	//	}
	//	return os;
	//}
}
