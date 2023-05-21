#include <string>
#include <iostream>
#pragma once

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

	std::istream& operator>>(std::istream& istr, TennisMatch& Ro);
	std::ostream& operator<<(std::ostream& ostr, TennisMatch& Ro);

	class TennisLog {
		TennisMatch* m_matchList{};
		int m_numOfMatch{};
	public:
		TennisLog() = default;
		TennisLog(const char* filename);
		~TennisLog();
		void addMatch(const TennisMatch& match);
		TennisLog findMatches(const std::string player);
		TennisMatch operator[](size_t);
		operator size_t();
	};

	std::ostream& operator<<(std::ostream& ostr, TennisLog& Ro);
}


