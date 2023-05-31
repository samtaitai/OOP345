#pragma once
#include "Queue.h"

namespace sdds {
	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
	public:
		bool push(const T& item);
	};

	template<typename T>
	inline bool UniqueQueue<T>::push(const T& item)
	{
		//override the inherited function push to prevent adding an item 
		//if it already exists in the UniqueQueue.
		bool result{};
		//unsigned int found{};

		if (100 > Queue<T, 100>::size()) {
			Queue<T, 100>::push(item);
			result = true;
		}

		//erase duplicate logic

		return result;
	}
	//push specialization
	template<>
	inline bool UniqueQueue<double>::push(const double& item)
	{
		//override the inherited function push to prevent adding an item 
		//if it already exists in the UniqueQueue.
		bool result{};
		//unsigned int found{};

		if (100 > Queue<double, 100>::size()) {
			Queue<double, 100>::push(item);
			result = true;
		}

		//erase duplicate logic

		return result;
	}

}
