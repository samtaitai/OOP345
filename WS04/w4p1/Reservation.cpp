/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 4 Jun 2023
* For trim function, credit is:  
* https://www.positioniseverything.net/cpp-string-trim/
*/
#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation(const string& res)
	{
		size_t idxColon = res.find(':');
		size_t idxC1 = res.find(',');
		size_t idxC2 = res.find(',', idxC1 + 1);
		size_t idxC3 = res.find(',', idxC2 + 1);
		size_t idxC4 = res.find(',', idxC3 + 1);

		//ID needs trimming
		m_id = res.substr(0, idxColon);
		m_id = this->trim(m_id);

		//name needs trimming
		m_name = res.substr(idxColon+1, (idxC1-idxColon-1));
		m_name = this->trim(m_name);

		//email needs trimming
		m_email = res.substr(idxC1 + 1, (idxC2 - idxC1 - 1));
		m_email = this->trim(m_email);
		m_email = "<" + m_email + ">";

		m_numOfPeople = stoi(res.substr(idxC2 + 1, (idxC3 - idxC2 - 1)));
		m_day = stoi(res.substr(idxC3 + 1, (idxC4 - idxC3 - 1)));
		m_hour = stoi(res.substr(idxC4 + 1));
	}
	Reservation& Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
		return *this;
	}
	ostream& Reservation::display(ostream& os) const
	{
		os << "Reservation ";
		os.width(10);
		os << m_id << ": ";
		os.width(20);
		os << m_name;
		os << "  ";
		os.setf(ios::left);
		os.width(20);
		os << m_email;
		if (m_hour >= 6 && m_hour <= 9) {
			os << "    Breakfast on day " << m_day << " @ " << m_hour << ":00 for ";
			if (m_numOfPeople == 1) {
				os << m_numOfPeople << " person." << endl;
			}
			else {
				os << m_numOfPeople << " people." << endl;
			}
		}
		else if (m_hour >= 11 && m_hour <= 15) {
			os << "    Lunch on day " << m_day << " @ " << m_hour << ":00 for ";
			if (m_numOfPeople == 1) {
				os << m_numOfPeople << " person." << endl;
			}
			else {
				os << m_numOfPeople << " people." << endl;
			}
		}
		else if (m_hour >= 17 && m_hour <= 21) {
			os << "    Dinner on day " << m_day << " @ " << m_hour << ":00 for ";
			if (m_numOfPeople == 1) {
				os << m_numOfPeople << " person." << endl;
			}
			else {
				os << m_numOfPeople << " people." << endl;
			}
		}
		else {
			os << "    Drinks on day " << m_day << " @ " << m_hour << ":00 for ";
			if (m_numOfPeople == 1) {
				os << m_numOfPeople << " person." << endl;
			}
			else {
				os << m_numOfPeople << " people." << endl;
			}
		}
		os.unsetf(ios::left);
		return os;
	}
	std::string Reservation::trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1);
		str.erase(0, str.find_first_not_of(WHITESPACE));
		return str;
	}
	ostream& operator<<(ostream& os, const Reservation& Ro)
	{
		return Ro.display(os);
	}
}
