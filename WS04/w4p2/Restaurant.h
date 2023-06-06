#pragma once
#include "Reservation.h"

namespace sdds {
	class Restaurant
	{
		Reservation** m_reservations{}; //array of pointers
		size_t m_cnt{};

	public:
		Restaurant() = default;
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		size_t size() const;
		std::ostream& display(std::ostream& os) const;
		Reservation* operator[](size_t idx) const;
	};
	static int getCalled{}; //only visible Restaurant module
	std::ostream& operator<<(std::ostream& os, const Restaurant& Ro);

}


