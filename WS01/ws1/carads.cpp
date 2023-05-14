#include <iostream>
#include "carads.h"

using namespace std;

namespace sdds {
    int listArgs(int argc, char* argv[])
    {
        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        for (int i = 0; i < argc; i++) {
            cout << i + 1 << ": " << argv[i] << endl;
        }
        cout << "--------------------------" << endl;
        return 0;
    }
    Cars& Cars::read(istream& is)
    {
        if (is) {
            is >> m_tag;
            is.ignore();
            is.get(m_brand, ',');
            is.get(m_model, ',');
            is >> m_year;
            is.ignore();
            is >> m_price;
            is.ignore();
            is >> m_isDiscount;
        }

        return *this;
    }
    void Cars::display(bool reset)
    {
        static int counter{};

        if (m_brand[0] != '\0') {
            cout.setf(ios::left);
            cout.width(2);
            cout << counter++; 
            cout.width(10);
            cout << m_brand;
            cout.width(15);
            cout << m_model;
            cout << m_year;
            cout.width(12);
            cout << m_price * (1+g_taxrate);
            cout.unsetf(ios::left);
            cout.width(12);
            if (m_isDiscount) {
                cout << m_price * 0.9;
            }
        }
        else { //If no car brand has been stored in the current object, this query should print:
            cout.setf(ios::left);
            cout.width(2);
            cout << "COUNTER. No Car";
        }

        //If the parameter is true, the counter is reset to the initial value.
        if (reset) counter = 0;

    }
    char Cars::getStatus()
    {
        return m_tag;
    }
}


