/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 22 May 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#pragma once
#include <string>
#include <iostream>

namespace sdds {

	struct TennisMatch {
		std::string m_tourID{}; //what is its default? 
		std::string m_tourName{};
		unsigned int m_matchID{};
		std::string m_winner{};
		std::string m_loser{};

		std::istream& read(std::istream& istr);
		std::ostream& display(std::ostream& ostr);
	};

	class TennisLog {
		TennisMatch* m_matchList{};
		int m_numOfMatch{};

		unsigned int countLines(const char* filename);

	public:
		TennisLog() = default;
		TennisLog(const char* filename);
		~TennisLog();
		TennisLog(const TennisLog& Ro); //with and without const makes difference
		TennisLog& operator=(const TennisLog& Ro);
		void addMatch(const TennisMatch& match);
		TennisLog findMatches(const std::string player); //should return value
		TennisMatch& operator[](size_t);
		operator size_t();
		operator bool() const;
	};

	std::istream& operator>>(std::istream& istr, TennisMatch& Ro);
	std::ostream& operator<<(std::ostream& ostr, TennisMatch& Ro);
	std::ostream& operator<<(std::ostream& ostr, TennisLog& Ro);
}

