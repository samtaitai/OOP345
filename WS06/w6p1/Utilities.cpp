#include <string>
#include <sstream>
#include <iostream>
#include "Utilities.h"
#include "Car.h"

using namespace std;

namespace sdds {
	Vehicle* Utilities::createInstance(std::istream& in) //single Car
	{
		Car result{};
		std::string strCars{};

		std::getline(in, strCars);
		if (strCars[0] == 'c' || strCars[0] == 'C') {

			std::stringstream row(strCars);
			try { result = Car(row); }
			catch (const char* err) { cout << err; }
		}
		return &result;
	}
	std::string Utilities::trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
}
