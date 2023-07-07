/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 7 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include "Racecar.h"

using namespace std;

namespace sdds {
	
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string temp{};
		std::getline(in, temp, '\n');
		m_booster = std::stod(temp);
		Car::setSpeed(m_booster);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed();
	}
}
