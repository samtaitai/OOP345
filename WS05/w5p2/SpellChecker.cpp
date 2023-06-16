#include <fstream>
#include "SpellChecker.h"

using namespace std;
namespace sdds {

	//static int initialization? 
	int SpellChecker::count[6]{};

	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);
		string strWords{};
		size_t idx1{};
		size_t idx2{};
		size_t cnt{};
		const std::string WHITESPACE = " \n\r\t\f\v";

		if (file) {
			do {
				std::getline(file, strWords);
				if (strWords != "") {
					idx1 = strWords.find_first_of(WHITESPACE);
					idx2 = strWords.find_last_of(WHITESPACE);
					m_badWords[cnt] = strWords.substr(0, idx1);
					m_goodWords[cnt] = strWords.substr(idx2 + 1);
					cnt++;
				}
			} while (file);
		}
		else {
			throw "Bad file name!";
		}
	}
	void SpellChecker::operator()(std::string& text) //m_desc
	{
		for (int i = 0; i < 6; i++) {
			if (text.find(m_badWords[i]) != -1) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				count[i]++;
				if (text.find(m_badWords[i]) != -1) {
					text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
					count[i]++;
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out)
	{
		out << "Spellchecker Statistics" << endl;
		for (int i = 0; i < 6; i++) {
			out.width(15);
			out << m_badWords[i];
			out << ": "; 
			out << count[i]; 
			out << " replacements" << endl;
		}
	}
}
