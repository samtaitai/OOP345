#include <vector>
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
	};
}


