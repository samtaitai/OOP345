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
		std::vector<Vehicle*>::iterator iter;

		cout << "--------------------------------" << endl;
		cout << "| Cars in the autoshop!        |" << endl;
		cout << "--------------------------------" << endl;
		/*for (iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
			cout << *iter << endl;
		}*/
		cout << "--------------------------------" << endl;
	}
}


