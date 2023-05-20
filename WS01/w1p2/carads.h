/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 19 May 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/

#include <iostream>
#ifndef SDDS_CARADS_H //pragma once = ifndef+define+endif
#define SDDS_CARADS_H

//global variable
extern double g_taxrate; //global variable declaration
extern double g_discount;

namespace sdds {

	int listArgs(int argc, char* argv[]);

	class Cars {
		char* m_brand{};
		char m_model[15 + 1]{};
		int m_year{};
		double m_price{};
		char m_tag{'N'};
		bool m_isDiscount{};

	public:
		Cars() = default;
		~Cars();
		Cars(Cars& Ro);
		Cars& operator=(const Cars& Ro);
		std::istream& read(std::istream& is);
		void display(bool reset);
		char getStatus();
		operator bool() const;
	};
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2); 
	//global function = outside class 
	//helper function = one of operand is class 
}

#endif

