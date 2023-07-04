#include <iostream>
#include "Vehicle.h"
#pragma once

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string trim(std::string& str);
}


