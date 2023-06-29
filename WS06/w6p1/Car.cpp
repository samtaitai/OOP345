#include <cstring>
#include <typeinfo>
#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car(std::istream& is)
	{
		int* iptr{ nullptr };
		char temp[256];
		strcpy(temp, "/0");

		m_tag = is.get();
		if (m_tag != ('c' || 'C')) throw "Invalid tag";
		else {
			is.ignore();
			//extract std::string from istream?
			is.get(temp, 255, ',');
			m_maker = std::string(temp);
			is.ignore();
			m_condition = is.get();
			if (m_condition != 'n' && m_condition != 'u' && m_condition != 'b') throw "Invalid condition";
			else {
				is.ignore();
				is >> m_speed;
				//iptr = dynamic_cast<int*>(&m_speed);
				//if (!iptr) throw "Invalid speed";
				if (sizeof(m_speed) != 8) throw "Invalid speed";
			}
		}


	}

	std::string Car::condition() const
	{
		std::string result{};

		if (m_condition == 'n') result = "new";
		else if (m_condition == 'u') result = "used";
		else if (m_condition == 'b') result = "broken";
		return result;
	}

	double Car::topSpeed() const
	{
		return m_speed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		out << "|";
		out.width(10);
		out << m_maker;
		out << "|";
		out.width(6);
		out << m_condition;
		out << "|";
		out.width(6);
		out << m_speed;
		out << "|" << endl;
	}
}


