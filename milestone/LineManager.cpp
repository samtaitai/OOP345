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

			for (auto s : stations) {

				bool found = find_if(m_activeLine.begin(), m_activeLine.end(),
					[&s](Workstation* w) { return s->getItemName() == w->getItemName(); }) != m_activeLine.end();
				if (!found) m_firstStation = s; break;
			}

			m_cntCustomerOrder = g_pending.size();
		}
		catch (...) {
			throw string("Something goes wrong");
		}
	}
	void LineManager::reorderStations()
	{
		std::vector<Workstation*> reordered;

		for (auto i = 0; i < m_activeLine.size()-1; i++) {
			if (m_activeLine[i]->getItemName() == m_activeLine[i + 1]->getNextStation()->getItemName()) {
				reordered.push_back(m_activeLine[i + 1]);
				reordered.push_back(m_activeLine[i]);
			}
			else {
				reordered.push_back(m_activeLine[i]);
				reordered.push_back(m_activeLine[i + 1]);
			}
		}
		m_activeLine = reordered; //use algorithm?
	}
	bool LineManager::run(std::ostream& os)
	{
		bool result{};
		static size_t count{};
		bool done{};
		os << "Line Manager Iteration: " << count++ << endl;
		while (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		while (!done) {
			for (auto station : m_activeLine) {
				station->fill(os);
				done = station->attemptToMoveOrder(); //if item moved, true 
			}
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

