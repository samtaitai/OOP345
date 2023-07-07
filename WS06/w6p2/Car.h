/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 7 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
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


