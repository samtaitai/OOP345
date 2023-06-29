#include <string>
#include <iostream>
#include "Vehicle.h"
#pragma once


namespace sdds {
	class Car: public Vehicle
	{
		char m_tag{};
		std::string m_maker{};
		char m_condition{};
		double m_speed{};

	public:
		Car(std::istream& is);
		std::string condition() const;	
		double topSpeed() const;
		void display(std::ostream& out) const;

	};
}


