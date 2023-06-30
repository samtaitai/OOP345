#include <string>
#include <iostream>
#include "Vehicle.h"
#pragma once


namespace sdds {
	class Car: public Vehicle
	{
		std::string m_tag{};
		std::string m_maker{};
		std::string m_condition{};
		double m_speed{};

	public:
		Car() = default;
		Car(std::istream& is);
		std::string condition() const;	
		double topSpeed() const;
		void display(std::ostream& out) const;

	};
}


