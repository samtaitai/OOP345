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
#include "Dictionary.h"

namespace sdds {
	template <typename T, unsigned int N>
	class Queue
	{
		T m_queue[N]; //what would be its default value? 
		//static member
		static unsigned int pushes;

	public:
		Queue();
		bool push(const T& item);
		T pop();
		unsigned int size();
		std::ostream& display(std::ostream& os = std::cout);
		T operator[](int index);
	};
	//initialization of static member
	template <typename T, unsigned int N>
	unsigned int Queue<T, N>::pushes{};
	
	template<typename T, unsigned int N>
	inline Queue<T, N>::Queue()
	{
		T temp{};

		for (unsigned int i = 0; i < N; i++) {
			m_queue[i] = temp;
		}
	}

	//speicialization of constructor
	template<>
	inline Queue<Dictionary, 100u>::Queue() {
		Dictionary temp{ "Empty Term", "Empty Substitute" };
		for (unsigned int i = 0; i < 100u; i++) {
			m_queue[i] = temp;
		}
	}
	
	template<typename T, unsigned int N>
	inline bool Queue<T, N>::push(const T& item)
	{
		bool result{};
		if (N >= pushes) {
			m_queue[pushes] = item;
			pushes++;
			result = true;
		}
		return result;
	}

	template<typename T, unsigned int N>
	inline T Queue<T, N>::pop()
	{
		T poped = m_queue[pushes - 1];

		for (unsigned int i = 0; i < pushes - 2; i++) {
			m_queue[i] = m_queue[i + 1];
		}
		m_queue[pushes - 1] = T();
		return poped;
	}

	template<typename T, unsigned int N>
	inline unsigned int Queue<T, N>::size()
	{
		return pushes;
	}

	template<typename T, unsigned int N>
	inline std::ostream& Queue<T, N>::display(std::ostream& os)
	{
		os << "----------------------" << std::endl;
		os << "| Dictionary Content |" << std::endl;
		os << "----------------------" << std::endl;
		for (unsigned int i = 0; i < pushes; i++) {
			os << m_queue[i] << std::endl;
		}
		os << "----------------------" << std::endl;
		return os;
	}

	template<typename T, unsigned int N>
	inline T Queue<T, N>::operator[](int index)
	{
		return m_queue[index];
	}

}


