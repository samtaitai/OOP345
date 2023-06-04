#include "Reservation.h"

namespace sdds {
	Reservation::Reservation(const std::string& res)
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

		m_numOfPeople = std::stoi(res.substr(idxC2 + 1, (idxC3 - idxC2 - 1)));
		m_day = std::stoi(res.substr(idxC3 + 1, (idxC4 - idxC3 - 1)));
		m_hour = std::stoi(res.substr(idxC4 + 1));
		
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& Ro)
	{
		return Ro.display(os);
	}
}
