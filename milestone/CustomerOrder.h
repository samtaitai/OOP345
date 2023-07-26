// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 26 July 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#include <iostream>
#include "Station.h"
#pragma once

namespace sdds {

	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
		//~Item() { delete this; }

	};
	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};
		static size_t m_widthField;

	public:
		CustomerOrder() = default;
		CustomerOrder(const std::string& row);
		CustomerOrder(const CustomerOrder& Ro);
		CustomerOrder(CustomerOrder&& Ro) noexcept;
		CustomerOrder& operator=(CustomerOrder&& Ro) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

	};
}


