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
		Car(std::istream& is, std::string temp);
		virtual std::string condition() const;	
		virtual double topSpeed() const;
		virtual void display(std::ostream& out) const;
		virtual ~Car() = default;

	};
}


