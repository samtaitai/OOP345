#include "Racecar.h"

using namespace std;

namespace sdds {
	
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string temp{};
		std::getline(in, temp, '\n');
		m_booster = std::stod(temp);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}
