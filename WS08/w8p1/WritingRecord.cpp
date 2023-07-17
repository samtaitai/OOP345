#include <algorithm>
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		std::string name{};
		std::string sin{};
		double salary{};
		EmployeeWage* temp{};
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		//check if SIN is the same
		//check if valid salary EmployeeWage::rangeValidator
		//check if valid SIN GeneratingList::idValidator
		//new EmployeeWage(id, salary)
		//then push it to activeEmp
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[i].id) {
					name = emp[i].name;
					sin = emp[i].id;
					salary = sal[i].salary;
					temp = new EmployeeWage(name, salary);
				}
			}
		}

		temp->rangeValidator(); //will be caught w8_p1.cpp

		if (activeEmp.idValidator(sin)) activeEmp += temp;

		return activeEmp;
	}
}