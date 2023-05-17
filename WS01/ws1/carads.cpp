#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "carads.h"

using namespace std;

//definition for global variables?
//do I adhere to one definition rule?
double g_taxrate{}; 
double g_discount{};  

namespace sdds {
    int listArgs(int argc, char* argv[])
    {
        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        for (int i = 0; i < argc; i++) {
            cout << "  " << i + 1 << ": " << argv[i] << endl;
        }
        cout << "--------------------------" << endl;
        cout << endl;
        return 0;
    }
    Cars& Cars::read(istream& is)
    {
        char discount{};

        if (is) {
            is >> m_tag;
            is.ignore();
            is.get(m_brand, 11, ','); //fix!! it takes all of them after tag
            is.ignore();
            is.get(m_model, 14, ',');
            is.ignore();
            is >> m_year;
            is.ignore();
            is >> m_price;
            is.ignore();
            is >> discount;
            if (discount == 'Y') m_isDiscount = true;
            else m_isDiscount = false;
        }

        return *this;
    }
    void Cars::display(bool reset)
    {
        static int counter{1};
        double taxedPrice = m_price * (1 + g_taxrate);

        //If the parameter is true, the counter is reset to the initial value.
        if (reset) counter = 1;

        if (m_brand[0] != '\0') {
            //cout << "  ";
            cout.setf(ios::left);   //align not working
            cout.width(2);
            cout << counter++;
            cout << ". ";
            cout.width(10);
            cout << m_brand;
            cout << "| ";
            cout.width(15);
            cout << m_model;
            cout << "| ";
            cout << m_year << " |";
            cout.unsetf(ios::left);
            cout.width(12);
            cout.setf(ios::fixed);                      //precision!(fixed)
            cout.precision(2);
            cout << taxedPrice;
            cout << "|";
            if (m_isDiscount) {
                cout.width(12);
                cout << taxedPrice * (1 - g_discount); //numbers are not right(fixed)
            }
            
            cout << endl;
        }
        /*
        else { //If no car brand has been stored in the current object, this query should print:
            cout.setf(ios::left);
            cout.width(2);
            cout << "COUNTER. No Car" << endl; //what is it for? 
        }
        */
        
    }
    char Cars::getStatus()
    {
        return m_tag;
    }
}


