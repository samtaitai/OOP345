#include <vector>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& row) { //row = record
		Utilities util;
		bool more = true;
		size_t pos = 0u;
		std::vector<Item*> temp;

		try
		{
			m_name = util.extractToken(row, pos, more);
			m_product = util.extractToken(row, pos, more);

			do {
				temp.push_back(new Item(util.extractToken(row, pos, more)));
				m_cntItem++;

			} while (more);

			m_lstItem = new Item * [m_cntItem];

			//citation chatGPT
			std::copy(temp.begin(), temp.end(), m_lstItem);

			if (m_widthField < util.getFieldWidth()) m_widthField = util.getFieldWidth();
		}
		catch (...) { cout << "   ERROR: No token.\n"; }
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& Ro) {
		throw "not allow copy operations";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& Ro) noexcept {
		*this = std::move(Ro);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& Ro) noexcept {
		if (this != &Ro) {
			delete[] m_lstItem;
			m_lstItem = Ro.m_lstItem;
			Ro.m_lstItem = nullptr;

			m_name = Ro.m_name;
			m_product = Ro.m_product;
			m_cntItem = Ro.m_cntItem;

			Ro.m_name = "";
			Ro.m_product = "";
			Ro.m_cntItem = 0;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder() {
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const {
		bool filled{true};
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) filled = false;
		}
		return filled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool filled{ true };
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) filled = false;
		}
		return filled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName) {
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << '[' << m_lstItem[i]->m_itemName << ']' << endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << '[' << m_lstItem[i]->m_itemName << ']' << endl;
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << '[';
			os << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName;
			if (m_lstItem[i]->m_isFilled) os << "FILLED" << endl;
			else os << " - TO BE FILLED" << endl;
		}
	}
}
