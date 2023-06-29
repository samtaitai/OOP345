#include <iostream>
#include "Vehicle.h"
#pragma once

namespace sdds {
	class Utilities
	{
	public:
		Vehicle* createInstance(std::istream& in);
	};
}


