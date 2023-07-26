#include "Workstation.h"

namespace sdds {
	Workstation::Workstation(const std::string& row) :Station(row)
	{
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool result{};

		//if all of m_orders.front().m_lstItem.m_itemName != this->getItemName()
		//or this->getQuantity <= 0
			//if m_pNextStation == nullptr -> go complete or incomplete => true
			//else false
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() <= 0) {
				if (m_pNextStation == this) { //this condition suspicious
					if (!m_orders.front().isOrderFilled()) { 
						g_incomplete.push_back(std::move(m_orders.front()));
					}
					else {
						g_completed.push_back(std::move(m_orders.front()));
					}
					m_orders.pop_front();
					result = true;
				}
				else {
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					result = true;
				}
			}
		}
		
		return result;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation != this) os << this->getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		else os << this->getItemName() << " --> End of Line" << std::endl;
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}


