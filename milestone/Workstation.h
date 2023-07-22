#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
#pragma once

namespace sdds {
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation;

	public:
		Workstation() = default;
		Workstation(const std::string& row);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		Workstation(const Workstation& Ro) = delete;
		Workstation(Workstation&& Ro) = delete;
		~Workstation() = default;
	};
}


