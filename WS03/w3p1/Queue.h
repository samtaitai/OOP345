#pragma once
#include <iostream>

namespace sdds {
	template <typename T, int N>
	class Queue
	{
		T m_queue[N]{};
		int m_capacity{};
		//static member
		static int pushes;

	public:
		bool push(const T& item);
		T pop();
		int size();
		std::ostream& display(std::ostream& os = std::cout);
		T operator[](int index);
		//static function
		//static int pushed() { return pushes; };
	};
	//initialization of static member
	template <typename T, int N>
	int Queue<T, N>::pushes{};

	//speicialization of..? 




	template<typename T, int N>
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

	template<typename T, int N>
	inline T Queue<T, N>::pop()
	{
		T poped = m_queue[pushes - 1];

		for (int i = 0; i < pushes - 2; i++) {
			m_queue[i] = m_queue[i + 1];
		}
		m_queue[pushes - 1] = T();
		return poped;
	}

	template<typename T, int N>
	inline int Queue<T, N>::size()
	{
		return pushes;
	}

	template<typename T, int N>
	inline std::ostream& Queue<T, N>::display(std::ostream& os)
	{
		os << "----------------------" << std::endl;
		os << "| Dictionary Content |" << std::endl;
		os << "----------------------" << std::endl;
		for (int i = 0; i < pushes; i++) {
			os << m_queue[i] << std::endl;
		}
		return os;
	}

	template<typename T, int N>
	inline T Queue<T, N>::operator[](int index)
	{
		return m_queue[index];
	}

}


