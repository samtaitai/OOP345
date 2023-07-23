#include <fstream>
#include "LineManager.h"

using namespace std;

namespace sdds {

	//definition without initial value
	std::deque<CustomerOrder> g_pending; 
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		ifstream in(file);
		string record{};
		Workstation* temp{};

		try {
			while (!in.eof()) {
				getline(in, record);
				temp = new Workstation(record); //why not smartpointer?
				m_activeLine.push_back(temp);
			}
			m_cntCustomerOrder = g_pending.size();
			m_firstStation = m_activeLine[0];
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

