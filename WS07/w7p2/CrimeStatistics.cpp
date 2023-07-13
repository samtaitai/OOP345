#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <numeric>
#include <iomanip>
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
			row.erase(row.begin(), row.end()); //avoid duplicating the last row

			std::getline(file, row, '\n');
			if (row.length() > 0) {
				Crime c;
				std::stringstream rowStream(row);

				rowStream.get(tempc, 25);
				c.province = std::string(tempc);
				c.province = trim(c.province);
				rowStream.ignore();

				rowStream.get(tempc, 25);
				c.district = std::string(tempc);
				c.district = trim(c.district);
				rowStream.ignore();

				rowStream.get(tempc, 25);
				c.crime = std::string(tempc);
				c.crime = trim(c.crime);
				rowStream.ignore();

				strcpy(tempc, "\0");

				rowStream.get(tempc, 5);
				temp = std::string(tempc);
				c.year = std::stoi(temp);
				rowStream.ignore();

				rowStream.get(tempc, 5);
				temp = std::string(tempc);
				c.numOfCases = std::stoi(temp);
				rowStream.ignore();

				rowStream.getline(tempc, 5);
				temp = std::string(tempc);
				c.numOfresolved = std::stoi(temp);

				statistics.push_back(c);
			}
		}
	}
	void CrimeStatistics::display(std::ostream& out) const
	{
		unsigned int totalCrime{};
		unsigned int totalResolved{};
		std::vector<unsigned int> temp(statistics.size());
		std::transform(statistics.begin(), statistics.end(), temp.begin(), [](Crime c) {return c.numOfCases; });
		totalCrime = std::accumulate(temp.begin(), temp.end(), 0);
		std::transform(statistics.begin(), statistics.end(), temp.begin(), [](Crime c) {return c.numOfresolved; });
		totalResolved = std::accumulate(temp.begin(), temp.end(), 0);

		for_each(statistics.begin(), statistics.end(), [&](const Crime& c) {
			out << "| ";
		out.width(21);
		out << std::left << c.province;
		out << " | ";
		out.width(15);
		out << c.district;
		out << " | ";
		out.width(20);
		out << c.crime;
		out << " | ";
		out.width(6);
		out << std::right << c.year;
		out << " | ";
		out.width(4);
		out << c.numOfCases;
		out << " | ";
		out.width(3);
		out << c.numOfresolved;
		out << " |" << endl;
			});
		out << "----------------------------------------------------------------------------------------" << endl;
		out << "| " << std::setw(79) << "Total Crimes : " << totalCrime << " | " << endl;
		out << "| " << std::setw(79) << "Total Resolved Cases : " << totalResolved << " | " << endl;

	}
	void CrimeStatistics::sort(const char* filter)
	{
		std::sort(statistics.begin(), statistics.end(), [filter](Crime c1, Crime c2) { 
			if (strcmp(filter, "Province") == 0) {
				return c1.province < c2.province;
			}
			else if (strcmp(filter, "Crime") == 0) {
				return c1.crime < c2.crime;
			}
			else if (strcmp(filter, "Cases") == 0) {
				return c1.numOfCases < c2.numOfCases;
			}
			else if (strcmp(filter, "Resolved") == 0) {
				return c1.numOfresolved < c2.numOfresolved;
			}
			  });
	}
	void CrimeStatistics::cleanList()
	{
		std::replace_if(statistics.begin(), statistics.end(), [](Crime c) {return c.crime.compare("[None]") == 0; }, "");
	}
	bool CrimeStatistics::inCollection(const char* crime) const
	{
		return std::any_of(statistics.begin(), statistics.end(), [crime](Crime c) { return c.crime.compare(crime) == 0; });
	}
	std::list<Crime> CrimeStatistics::getListForProvince(const char* province) const
	{
		std::list<Crime> result;
		std::copy_if(statistics.begin(), statistics.end(), std::back_inserter(result), 
			[province](Crime c) { return c.province.compare(province) == 0; });

		return result;
	}
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| ";
		out.width(21);
		out << std::left << theCrime.province;
		out << " | ";
		out.width(15);
		out << theCrime.district;
		out << " | ";
		out.width(20);
		out << theCrime.crime;
		out << " | ";
		out.width(6);
		out << std::right << theCrime.year;
		out << " | ";
		out.width(4);
		out << theCrime.numOfCases;
		out << " | ";
		out.width(3);
		out << theCrime.numOfresolved;
		out << " |";
		return out;
	}
	std::string trim(std::string& str)
	{
		const std::string WHITESPACE = " \n\r\t\f\v";
		str.erase(str.find_last_not_of(WHITESPACE) + 1); //"..charlie****" from e+1 to end
		str.erase(0, str.find_first_not_of(WHITESPACE)); //"****charlie" from start to last *
		return str;
	}
	Crime& Crime::operator=(const char* cstring)
	{
		this->crime = cstring;
		return *this;
	}
}


