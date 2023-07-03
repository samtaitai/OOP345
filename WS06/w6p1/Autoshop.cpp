#include <iostream>
#include "Autoshop.h"

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
		}
		cout << "--------------------------------" << endl;
	}
}


