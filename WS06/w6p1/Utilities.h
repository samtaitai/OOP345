#include <iostream>
#include "Vehicle.h"
#pragma once

namespace sdds {
	class Utilities
	{
	public:
		static Vehicle* createInstance(std::istream& in);
		static std::string trim(std::string& str);
	};
}


