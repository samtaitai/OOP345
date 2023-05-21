#include <string>
#include <iostream>
#include <fstream>
#include "TennisLog.h"

using namespace std;

namespace sdds {
	std::istream& TennisMatch::read(std::istream& istr)
	{
		if (istr) {
			getline(istr, m_tourID, ',');
			getline(istr, m_tourName, ',');
			istr >> m_matchID;
			istr.ignore();
			getline(istr, m_winner, ',');
			getline(istr, m_loser, '\n');
		}
		return istr;
	}
	std::ostream& TennisMatch::display(std::ostream& ostr)
	{
		if (m_matchID != 0) {
			ostr.width(20);
			ostr.fill('.');
			ostr << "Tourney ID";
			ostr << " : ";
			ostr.setf(ios::left);
			ostr.width(30);
			ostr << m_tourID << endl;

			ostr.unsetf(ios::left);
			ostr.width(20);
			ostr << "Match ID";
			ostr << " : ";
			ostr.setf(ios::left);
			ostr.width(30);
			ostr << m_matchID << endl;
			ostr.unsetf(ios::left);
			ostr.width(20);
			ostr << "Tourney";
			ostr << " : ";
			ostr.setf(ios::left);
			ostr.width(30);
			ostr << m_tourName << endl;
			ostr.unsetf(ios::left);
			ostr.width(20);
			ostr << "Winner";
			ostr << " : ";
			ostr.setf(ios::left);
			ostr.width(30);
			ostr << m_winner << endl;
			ostr.unsetf(ios::left);
			ostr.width(20);
			ostr << "Loser";
			ostr << " : ";
			ostr.setf(ios::left);
			ostr.width(30);
			ostr << m_loser << endl;
			ostr.fill(' '); //need it? 
		}
		else {
			ostr << "Empty Match";
		}
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, TennisMatch& Ro)
	{
		return Ro.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, TennisMatch& Ro)
	{
		return Ro.display(ostr);
	}
	std::ostream& operator<<(std::ostream& ostr, TennisLog& Ro)
	{
		for (int i = 0; i < size_t(Ro); i++) {
			Ro[i].display(ostr);
		}
		return ostr;
	}
	unsigned int TennisLog::countLines(const char* filename)
	{
		unsigned int lines = 0u;
		ifstream nums(filename);
		while (nums) {
			lines += (nums.get() == '\n');
		}
		return lines;
	}
	TennisLog::TennisLog(const char* filename)
	{
		unsigned int count{};
		ifstream file(filename);
		
		//read the file to count the number of matches in the file (except for 1st line)
		count = countLines(filename); 

		//allocate dynamic memory for the array of matches based on the number found
		m_numOfMatch = count - 1; //match # = rows # - 1st row 
		m_matchList = new TennisMatch[m_numOfMatch]; 
		
		//reread the file from the beginning to load the actual match data into the array
		file.seekg(0, file.beg);
		file.ignore(9999, '\n'); //discard 1st row
		for (int i = 0; i < m_numOfMatch; i++) {
			file >> m_matchList[i]; 
		}
	}
	TennisLog::~TennisLog()
	{
		delete[] m_matchList;
	}
	void TennisLog::addMatch(const TennisMatch& match)
	{
		//Resize the array appropriately to accommodate the new object and avoid memory leaks
		TennisMatch* temp{};
		temp = new TennisMatch[m_numOfMatch + 1];
		for (int i = 0; i < m_numOfMatch; i++) {
			temp[i] = m_matchList[i];
		}
		delete[] m_matchList;
		temp[m_numOfMatch] = match;

		m_numOfMatch = m_numOfMatch + 1;
		m_matchList = new TennisMatch[m_numOfMatch];
		for (int i = 0; i < m_numOfMatch; i++) {
			m_matchList[i] = temp[i];
		}
		delete[] temp;
	}
	TennisLog TennisLog::findMatches(const std::string player)
	{
		TennisLog result;

		for (int i = 0; i < m_numOfMatch; i++) {
			if (m_matchList[i].m_winner == player || m_matchList[i].m_loser == player) {
				addMatch(m_matchList[i]);
			}
		}
		return result;
	}
	TennisMatch& TennisLog::operator[](size_t num)
	{
		TennisMatch result;
		if (m_matchList) {
			return m_matchList[num]; //double return ok??
		}
		return result;
	}
	TennisLog::operator size_t()
	{
		return m_numOfMatch;
	}
}