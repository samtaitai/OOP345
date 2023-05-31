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
#include <string>
#include <iostream>

namespace sdds {
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
		
		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
		Dictionary();
		std::ostream& display(std::ostream& os) const;
		// ==operator 
		bool operator==(Dictionary& Ro);
	};
	std::ostream& operator<< (std::ostream& os, const Dictionary& Ro);
}


