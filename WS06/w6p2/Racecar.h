/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 7 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include <iostream>
#include "Car.h"
#pragma once

namespace sdds {
	class Racecar: public Car
	{
		double m_booster{};

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;

	};
}


