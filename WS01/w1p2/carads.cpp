#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
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
    istream& operator>>(istream& is, Cars& car)
    {
        car.read(is);
        return is;
    }
    void operator>>(const Cars& car1, Cars& car2)
    {
        //copies in the second parameter the content of the first parameter.
    }
    Cars::~Cars()
    {
        delete[] m_brand;
    }
    Cars::Cars(Cars& Ro)
    {
        if (Ro) operator=(Ro);
    }
    Cars& Cars::operator=(const Cars& Ro)
    {
        if (Ro.m_brand && this != &Ro) {
            delete[] m_brand;
            m_brand = new char[strlen(Ro.m_brand) + 1]; //how to use string library?
            strcpy(m_brand, Ro.m_brand);
            strcpy(m_model, Ro.m_model);
            m_year = Ro.m_year;
            m_price = Ro.m_price;
            m_tag = Ro.m_tag;
            m_isDiscount = Ro.m_isDiscount;
        }
        return *this;
    }
    Cars& Cars::read(istream& is)
    {
        char discount{};
        char temp[512];
        strcpy(temp, "\0");

        if (is) {
            is >> m_tag;
            is.ignore();
            is.get(temp, 511, ','); 
            if (!is.fail()) {
                delete[] m_brand;
                m_brand = new char[strlen(temp) + 1];
                strcpy(m_brand, temp);
                is.ignore();
            }
            else {
                is.clear();
                is.ignore(9999, '\n');
            }
            //is.ignore();
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

        if (m_brand && m_model[0] != '\0') {
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
    Cars::operator bool() const
    {
        return m_tag == 'N' && m_brand != nullptr;
    }
}


