#pragma once
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
		const Restaurant* m_pReservations{}; //array of 'array of pointers(from each restaurant)'  
		size_t m_cnt{};

	public:
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		std::ostream& display(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, ConfirmationSender& Ro);

}


