#pragma once
#include <string>
#include <iostream>

namespace sdds {
	template <typename T>
	class Collection
	{
		std::string m_name;
		T* m_array;
		int m_cnt;
		void (*m_funcPtr)(const Collection<T>&, const T&); //??

	public:
		Collection(const std::string& name);
		~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
	};
	template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& Ro);

	template<typename T>
	Collection<T>::Collection(const std::string& name)
	{
		m_name = name;
		m_array = nullptr;
		m_cnt = 0;
		m_funcPtr = nullptr;
	}

	template<typename T>
	Collection<T>::~Collection() {
		delete[] m_array;
		delete[] m_funcPtr;
	}

	template<typename T>
	const std::string& Collection<T>::name() const {
		return m_name;
	}

	template<typename T>
	size_t Collection<T>::size() const {
		return m_cnt;
	}

	template<typename T>
	void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&)) {
		m_funcPtr = observer;
	}

	template<typename T>
	Collection<T>& Collection<T>::operator+=(const T& item) {
		bool found{};
		T* temp = nullptr;

		for (int i = 0; i < m_cnt; i++) {
			if (m_array[i].title() == item.title()) found = true;
		}

		if (found) {
			temp = new T[m_cnt + 1];
			for (int i = 0; i < m_cnt; i++) {
				temp[i] = m_array[i];
			}
			temp[m_cnt] = item;
			delete[] m_array;
			m_cnt++;
			m_array = new T[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_array[i] = temp[i];
			}
			delete[] temp;
		}
		//if an observer has been registered, this operator calls the observer 
		//function passing the current object (*this) and the new item as arguments.
		m_funcPtr(*this, item);
	}

	template<typename T>
	T& Collection<T>::operator[](size_t idx) const {

	}

	template<typename T>
	T* Collection<T>::operator[](const std::string& title) const {

	}
}



