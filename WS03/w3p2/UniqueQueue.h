#pragma once
#include "Queue.h"
#include "Dictionary.h"

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
		unsigned int size = Queue<T, 100>::size();
		bool found{};

		//erase duplicate logic
		for (unsigned int i = 0; i < size; i++) {
			if (Queue<T, 100>::operator[](i) == item) found = true; //how to? 
		}

		if (100 > Queue<T, 100>::size() && found == false) {
			Queue<T, 100>::push(item);
			result = true;
		}
		return result;
	}
	//push specialization
	template<>
	inline bool UniqueQueue<double>::push(const double& item)
	{
		//override the inherited function push to prevent adding an item 
		//if it already exists in the UniqueQueue.
		bool result{};
		unsigned int size = Queue<double, 100>::size();
		bool found{};

		//erase duplicate logic
		for (unsigned int i = 0; i < size; i++) {
			if (item == Queue<double, 100>::operator[](i)) found = true;
		}

		if (100 > Queue<double, 100>::size() && found == false) {
			Queue<double, 100>::push(item);
			result = true;
		}
		return result;
	}

}
