#include <string>
#include <sstream>
#include <iostream>
#include <cstring>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds {
	Vehicle* createInstance(std::istream& in) //single Car
	{
		Vehicle* result{};
		std::string strCars{};

		std::getline(in, strCars);
		strCars = trim(strCars);
		std::stringstream row(strCars);

		if (strCars[0] == 'c' || strCars[0] == 'C') {

			try {
				result = new Car(row); //'dynamically'
			}
			catch (const char* err) { cout << err; }
		}
		else if (strCars[0] == 'r' || strCars[0] == 'R') {

			try {
				result = new Racecar(row);
			}
			catch (const char* err) { cout << err; }
		}
		else if (strCars[0] == '\0') {} //cause while(file) runs extra +1 
		else {
			throw "Unrecognized record type: [t]"; //how? 
		}

		return result;
	}
	std::string trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
	
}
