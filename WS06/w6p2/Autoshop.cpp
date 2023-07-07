/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 7 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include <iostream>
#include "Autoshop.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		cout << "--------------------------------" << endl;
		cout << "| Cars in the autoshop!        |" << endl;
		cout << "--------------------------------" << endl;

		for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
			
			(*iter)->display(out);
			out << endl;
			
		}
		cout << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop()
	{
		for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) delete *iter;
	}
}


