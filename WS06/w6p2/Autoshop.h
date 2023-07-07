/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 7 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include <vector>
#include <list>
#include "Vehicle.h"
#pragma once

namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
		
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	};
	template<typename T>
	void Autoshop::select(T test, std::list<const Vehicle*>& vehicles)
	{
		for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
			if (test(*iter)) vehicles.push_back(*iter);
		}
	}
}


