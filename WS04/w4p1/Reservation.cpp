#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation(const string& res)
	{
		//receives the reservation as a string
		//extracting information about the reservation from the string and storing the tokens in the instance's attributes
		//ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
		//remove(res.begin(), res.end(), ' ');
		
		size_t idxColon = res.find(':');
		size_t idxC1 = res.find(',');
		size_t idxC2 = res.find(',', idxC1 + 1);
		size_t idxC3 = res.find(',', idxC2 + 1);
		size_t idxC4 = res.find(',', idxC3 + 1);

		//ID needs trimming
		m_id = res.substr(0, idxColon);

		//name needs trimming
		m_name = res.substr(idxColon+1, (idxC1-idxColon-1));

		//email needs trimming
		m_email = res.substr(idxC1 + 1, (idxC2 - idxC1 - 1));

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
		if (m_hour >= 6 && m_hour <= 9) {
			os.width(10);
			os << m_id << ": ";
			os.width(20);
			os << m_name;
			os.width(20);
			os.setf(ios::left);
			os << '<' << m_email << '>';
			os.unsetf(ios::left);
			os << "Breakfast on day " << m_day << " @ " << m_hour << ":00 for ";
			if (m_numOfPeople == 1) {
				os << m_numOfPeople << " person." << endl;
			}
			else {
				os << m_numOfPeople << " people." << endl;
			}
		}
		else if (m_hour >= 11 && m_hour <= 15) {
		}
		else if (m_hour >= 17 && m_hour <= 21) {
		}
		else {
		}
		return os;
	}
	ostream& operator<<(ostream& os, const Reservation& Ro)
	{
		return Ro.display(os);
	}
}
