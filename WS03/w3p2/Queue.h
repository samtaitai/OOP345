/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 30 May 2023
* Citation:
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Dictionary.h"

namespace sdds {
	template <typename T, unsigned int N>
	class Queue
	{
		T m_queue[N]; //what would be its default value? 
		unsigned int m_queueLength;
		//static member: empty one for any types
		static T dummy;

	public:
		Queue();
		Queue(unsigned int capacity);
		virtual ~Queue() = default;
		virtual bool push(const T& item); //looking for update ver
		T pop();
		unsigned int size();
		std::ostream& display(std::ostream& os = std::cout);
		T operator[](unsigned int index);
	};

	template <typename T, unsigned int N>
	T Queue<T, N>::dummy{};

	//initialization(specialize) of static member
	template <>
	Dictionary Queue<Dictionary, 100u>::dummy{ "Empty Term", "Empty Substitute" };
	//either is fine
	//Dictionary Queue<Dictionary, 100u>::dummy = Dictionary{ "Empty Term", "Empty Substitute" };
	
	template<typename T, unsigned int N>
	inline Queue<T, N>::Queue()
	{
		T temp{};
		
		for (unsigned int i = 0; i < N; i++) {
			m_queue[i] = temp;
		}
		m_queueLength = 0;
	}
	

	template<typename T, unsigned int N>
	inline Queue<T, N>::Queue(unsigned int capacity)
	{
		T temp{};

		for (unsigned int i = 0; i < capacity; i++) {
			m_queue[i] = temp;
		}
		m_queueLength = 0;
	}
	
	template<typename T, unsigned int N>
	inline bool Queue<T, N>::push(const T& item)
	{
		bool result{};
		if (N > m_queueLength) {
			m_queue[m_queueLength] = item;
			m_queueLength++;
			result = true;
		}
		return result;
	}

	template<typename T, unsigned int N>
	inline T Queue<T, N>::pop()
	{
		T poped = m_queue[0];

		for (unsigned int i = 1; i < m_queueLength; i++) {
			m_queue[i-1] = m_queue[i];
		}
		m_queue[m_queueLength - 1] = T();
		m_queueLength--;
		return poped;
	}

	template<typename T, unsigned int N>
	inline unsigned int Queue<T, N>::size()
	{
		return m_queueLength;
	}

	template<typename T, unsigned int N>
	inline std::ostream& Queue<T, N>::display(std::ostream& os)
	{
		os << "----------------------" << std::endl;
		os << "| Dictionary Content |" << std::endl;
		os << "----------------------" << std::endl;
		for (unsigned int i = 0; i < m_queueLength; i++) {
			os << m_queue[i] << std::endl;
		}
		os << "----------------------" << std::endl;
		return os;
	}

	template<typename T, unsigned int N>
	inline T Queue<T, N>::operator[](unsigned int index)
	{
		T result{};
		if (index >= m_queueLength) result = dummy;
		else result = m_queue[index];
		return result;
	}

}


