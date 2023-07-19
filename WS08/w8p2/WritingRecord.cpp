/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 19 July 2023
* I have done all the coding by myselfand only copied the code that
* my professor provided to complete my workshopsand assignments.
*/
#include <memory>
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		std::string name{};
		std::string sin{};
		double salary{};
		EmployeeWage* temp{};
		
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					name = emp[i].name;
					sin = emp[i].id;
					salary = sal[j].salary;
					temp = new EmployeeWage(name, salary);
					temp->rangeValidator(); //will be caught w8_p1.cpp
					if (activeEmp.idValidator(sin)) {
						activeEmp += temp;
					}
					delete temp;
				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		std::string name{};
		std::string sin{};
		double salary{};

		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					name = emp[i].name;
					sin = emp[i].id;
					salary = sal[j].salary;
					std::unique_ptr<EmployeeWage> temp(new EmployeeWage(name, salary));
					temp->smartRangeValidator(); //will be caught w8_p1.cpp
					if (activeEmp.idValidator(sin)) {
						activeEmp += std::move(temp);
					}
				}
			}
		}

		return activeEmp;
	}
}