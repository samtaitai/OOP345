#include <sstream>
#include <typeinfo>
#include "Car.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	Car::Car(std::istream& is)
	{
		std::string temp{};

		std::getline(is, m_tag, ','); //enable to use getline again

		if (m_tag.compare("c") == 0 || m_tag.compare("C") == 0) {
			std::getline(is, m_maker, ',');
			m_maker = trim(m_maker);
			std::getline(is, m_condition, ',');
			m_condition = trim(m_condition);
			if (m_condition.compare("n") == 0 ||
				m_condition.compare("u") == 0 ||
				m_condition.compare("b") == 0) {
				std::getline(is, temp, '\n');
				m_speed = std::stod(temp);
				if (sizeof(m_speed) != 8) throw "Invalid speed";
			}
			else throw "Invalid condition";
		}
		else throw "Invalid tag";
	}

	std::string Car::condition() const
	{
		std::string result{};

		if (m_condition.compare("n") == 0) result = "new";
		else if (m_condition.compare("u") == 0) result = "used";
		else if (m_condition.compare("b") == 0) result = "broken";
		return result;
	}

	double Car::topSpeed() const
	{
		return m_speed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out.width(10);
		out << m_maker;
		out << " | ";
		out.width(6);
		out.setf(ios::left);
		if (m_condition.compare("n") == 0) out << "new";
		else if (m_condition.compare("u") == 0) out << "used";
		else if (m_condition.compare("b") == 0) out << "broken";
		out.unsetf(ios::left);
		out << " | ";
		out.width(6);
		out.setf(ios::fixed);
		out.precision(2);
		out << m_speed;
		out << " |" << endl;
	}
	
}


