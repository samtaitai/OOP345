// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 26 July 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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

			//
			std::copy(temp.begin(), temp.end(), m_lstItem);

			//for (auto item : temp) delete item; error
			
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
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
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
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
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
		bool done{};

		for (size_t i = 0; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName &&
				!m_lstItem[i]->m_isFilled) { //breakthrough
				if (station.getQuantity() > 0) {
					if (!done) {
						m_lstItem[i]->m_isFilled = true;
						done = true;
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
						station.updateQuantity();
						os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << ']' << endl;
					}
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << ']' << endl;
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
			os << setfill(' ') << left << setw(m_widthField-1) << m_lstItem[i]->m_itemName;
			if (m_lstItem[i]->m_isFilled) os << "FILLED" << endl;
			else os << "- TO BE FILLED" << endl;
		}
	}
}
