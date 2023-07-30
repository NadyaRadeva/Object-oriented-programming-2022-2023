#include <string>
#include <vector>
#include <iostream>

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

class Employee {
	std::string name;
	double salary;

public:
	Employee(const std::string& name, double salary);
	double getSalary();

	friend std::ostream& operator<<(std::ostream& str, const Employee& obj);
};

#endif
