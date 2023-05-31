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
		//static member
		static T dummy;
		static unsigned int pushes;

	public:
		Queue() = default;
		Queue(unsigned int capacity);
		virtual ~Queue() = default;
		virtual bool push(const T& item); //looking for update ver
		T pop();
		unsigned int size();
		std::ostream& display(std::ostream& os = std::cout);
		T operator[](unsigned int index);
	};

	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
	public:
		bool push(const T& item);
	};

	//initialization of static member
	template <typename T, unsigned int N>
	unsigned int Queue<T, N>::pushes{};

	template <typename T, unsigned int N>
	T Queue<T, N>::dummy{};

	//initialization of static member
	template <>
	Dictionary Queue<Dictionary, 100u>::dummy{ "Empty Term", "Empty Substitute" };
	
	/*
	template<typename T, unsigned int N>
	inline Queue<T, N>::Queue()
	{
		T temp{};

		for (unsigned int i = 0; i < N; i++) {
			m_queue[i] = temp;
		}
	}
	*/

	template<typename T, unsigned int N>
	inline Queue<T, N>::Queue(unsigned int capacity)
	{
		T temp{};

		for (unsigned int i = 0; i < capacity; i++) {
			m_queue[i] = temp;
		}
	}
	
	template<typename T, unsigned int N>
	inline bool Queue<T, N>::push(const T& item)
	{
		bool result{};
		if (N > pushes) {
			m_queue[pushes-1] = item;
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
	inline T Queue<T, N>::operator[](unsigned int index)
	{
		T result{};
		if (index >= pushes) result = dummy;
		else result = m_queue[index];
		return result;
	}

	template<typename T>
	inline bool UniqueQueue<T>::push(const T& item)
	{
		//override the inherited function push to prevent adding an item 
		//if it already exists in the UniqueQueue.
		bool result{};
		unsigned int found{};

		for (unsigned int i = 0; i < pushes; i++) {
			if (m_queue[i] == item) found += 1;
		}

		if (N > pushes && found == 0) {
			m_queue[pushes - 1] = item;
			pushes++;
			result = true;
		}
		return result;
	}

	//push specialization
	template<>
	inline bool UniqueQueue<double>::push(const double& item) {
		bool result{};
		unsigned int found{};

		for (unsigned int i = 0; i < pushes; i++) {
			if (std::abs(m_queue[i] - item) <= 0.005) found += 1;
		}

		if (N > pushes && found == 0) {
			m_queue[pushes - 1] = item;
			pushes++;
			result = true;
		}
		return result;
	}
}


