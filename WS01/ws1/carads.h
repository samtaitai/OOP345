#include <iostream>
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

//global variable
extern double g_taxrate; //LNK2001 unresolved external symbol error!
extern double g_discount;

namespace sdds {

	int listArgs(int argc, char* argv[]);

	class Cars {
		char m_brand[10 + 1]{};
		char m_model[15 + 1]{};
		int m_year{};
		double m_price{};
		char m_tag{'N'};
		bool m_isDiscount{};

	public:
		Cars() = default;
		Cars& read(std::istream& is);
		void display(bool reset);
		char getStatus();
	};

}

#endif

