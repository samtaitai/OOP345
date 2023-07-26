// Name: Soyon Lee
// Seneca Student ID: 179142211
// Seneca email: slee550@myseneca.ca
// Date of completion: 26 July 2023
//
// how to use find_if in the LM constructor was inspired by chatGPT.   
#include <fstream>
#include <algorithm>
#include <map>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	//definition without initial value
	std::deque<CustomerOrder> g_pending; 
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{ 
		ifstream in(file);
		string first{};
		string second{};
		string row{};

		try {
			//m_activeLine
			while (!in.eof()) {
				Utilities util;
				bool more = true;
				size_t pos = 0u;

				getline(in, row);
				first = util.extractToken(row, pos, more);
				second = util.extractToken(row, pos, more);
			
				auto it1 = find_if(stations.begin(), stations.end(),
					[&first](Workstation* station) {return station->getItemName() == first; });
				m_activeLine.push_back(*it1);

				auto it2 = find_if(stations.begin(), stations.end(),
					[&second](Workstation* station) {return station->getItemName() == second; });
				
				//bookcase->bookcase can't fix it
				if(it2 != stations.end()) (*it1)->setNextStation(*it2);
				
			} 
			//m_firstStation
			for (auto s : stations) {

				bool found{};
				vector<Workstation*> next;

				transform(m_activeLine.begin(), m_activeLine.end(),
					back_inserter(next), [](Workstation* w) { return w->getNextStation(); });
				
				if (any_of(next.begin(), next.end(),
					[&s](Workstation* w) { return s->getItemName() == w->getItemName(); })) {
					found = true;
				}
				if (!found) {
					m_firstStation = s;
				}
			}
			//m_cntCustomerOrder
			m_cntCustomerOrder = g_pending.size();
		}
		catch (...) {
			throw string("Something goes wrong");
		}
	}
	void LineManager::reorderStations()
	{
		std::vector<Workstation*> reordered;

		reordered.push_back(m_firstStation);
		for (auto i = 0; i < m_activeLine.size()-1; i++) {
			reordered.push_back(reordered[i]->getNextStation());
		}
		copy(reordered.begin(), reordered.end(), m_activeLine.begin());

	}
	bool LineManager::run(std::ostream& os)
	{
		bool result{};
		static size_t count{};

		os << "Line Manager Iteration: " << ++count << endl;

		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		
		for (auto station : m_activeLine) {
			//os << "fill: " << station->getItemName() << endl;
			station->fill(os);
		}
		for (auto station : m_activeLine) {
			//os << "move: " << station->getItemName() << endl;
			station->attemptToMoveOrder();
		}
				
		if (m_cntCustomerOrder == g_completed.size() + g_incomplete.size()) result = true;
		return result;
	}
	void LineManager::display(std::ostream& os)
	{
		for (auto station : m_activeLine) {
			station->display(os);
		}
	}
}

