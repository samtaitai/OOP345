// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 8 July 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#pragma once

namespace sdds {
	class Station
	{
		int m_id{};
		std::string m_name{};
		std::string m_desc{};
		size_t m_nextSerial{};
		size_t m_quantity{};
		static size_t m_widthField;
		static unsigned int id_generator;

	public:
		Station(const std::string& row);
		const std::string& getItemName() const;
		size_t getNextSerialNumber() const;
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};
}


