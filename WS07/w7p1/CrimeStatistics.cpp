#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include "CrimeStatistics.h"

using namespace std;
namespace sdds {
	CrimeStatistics::CrimeStatistics(const char* filename)
	{
		std::ifstream file(filename);
		std::string row{};
		std::string temp{};
		char tempc[30] = {"\0"};

		if (!file) {
			throw "ERROR: Cannot open file";
		}
		while(file) {
			
			strcpy(tempc, "\0");
			std::getline(file, row, '\n');
			if (row.length() > 0) {
				Crime c;
				std::stringstream rowStream(row);

				rowStream.get(tempc, 25);
				c.province = std::string(tempc);
				c.province = trim(c.province);
				rowStream.get(tempc, 25);
				c.district = std::string(tempc);
				c.district = trim(c.district);
				rowStream.get(tempc, 25);
				c.crime = std::string(tempc);
				c.crime = trim(c.crime);
				strcpy(tempc, "\0");
				rowStream.get(tempc, 5);
				temp = std::string(tempc);
				c.year = std::stoi(temp);
				rowStream.get(tempc, 5);
				temp = std::string(tempc);
				c.numOfCases = std::stoi(temp);
				rowStream.getline(tempc, 5);
				temp = std::string(tempc);
				c.numOfresolved = std::stoi(temp);
				statistics.push_back(c);
			}
			//file.ignore();
		}
	}
	void CrimeStatistics::display(std::ostream& out) const
	{
		for_each(statistics.begin(), statistics.end(), [&](const Crime& c) {
			out << "| ";
		out.width(21);
		//out.setf(ios::left);
		out << c.province;
		out << " | ";
		out.width(15);
		out << c.district;
		out << " | ";
		out.width(20);
		out << c.crime;
		out << " | ";
		//out.unsetf(ios::left);
		out.width(6);
		out << c.year;
		out << " | ";
		out.width(4);
		out << c.numOfCases;
		out << " | ";
		out.width(3);
		out << c.numOfresolved;
		out << " |" << endl;
			});
	}
	std::string trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
}


