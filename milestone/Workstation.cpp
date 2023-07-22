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

		if (m_orders.front().isOrderFilled() || this->getQuantity() <= 0) {
			if (m_pNextStation == nullptr) {
				if (!m_orders.front().isOrderFilled()) g_incomplete.push_back(m_orders.front());
				else g_completed.push_back(m_orders.front());
			}
			else {
				m_pNextStation->m_orders.push_back(m_orders.front());
			}
			result = true;
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
		/*for (auto order : m_orders) {
			if (order == m_orders.back()) {
			}
			else {
				for (size_t i = 0; i < order.getCntItem() - 1; i++) {
					os << order.getLstItem()[i]->m_itemName << " --> "
						<< order.getLstItem()[i + 1]->m_itemName << std::endl;
				}
			}
			
		}*/
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(newOrder);
		return *this;
	}
}


