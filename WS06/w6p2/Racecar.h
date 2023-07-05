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


