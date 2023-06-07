/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 6 June 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#pragma once
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
		const Reservation** m_ppReservations{}; 
		size_t m_cnt{};

	public:
		ConfirmationSender() = default;
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& Ro);
		ConfirmationSender& operator=(const ConfirmationSender& Ro);
		ConfirmationSender(ConfirmationSender&& Ro) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& Ro) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		size_t size() const;
		std::ostream& display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, ConfirmationSender& Ro);

}


