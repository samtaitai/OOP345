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
		TennisLog(TennisLog& Ro);
		TennisLog& operator=(TennisLog& Ro);
		void addMatch(const TennisMatch& match);
		TennisLog& findMatches(const std::string player);
		TennisMatch& operator[](size_t);
		operator size_t();
		operator bool() const;
	};

	std::istream& operator>>(std::istream& istr, TennisMatch& Ro);
	std::ostream& operator<<(std::ostream& ostr, TennisMatch& Ro);
	std::ostream& operator<<(std::ostream& ostr, TennisLog& Ro);
}

