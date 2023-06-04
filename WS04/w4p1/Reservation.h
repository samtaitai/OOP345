#pragma once
#include <string>
#include <iostream>

namespace sdds {
	//a class that manages information about a single reservation
	class Reservation
	{
		std::string m_id{};
		std::string m_name{};
		std::string m_email{};
		int m_numOfPeople{};
		int m_day{};
		int m_hour{};

	public:
		Reservation() = default;
		Reservation(const std::string& res);
		Reservation& update(int day, int time);
		std::ostream& display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Reservation& Ro);
}


