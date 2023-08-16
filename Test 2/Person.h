#ifndef _PERSON_H
#define _PERSON_H

#include<string>
#include<iostream>

class Person {
protected:
	unsigned id;
	static int counter;
	std::string name;
	unsigned int age;
	std::string businessCard;
	double skills;

public:
	Person(std::string _name, unsigned int _age, std::string _businessCard, double _skills);
	unsigned getId() const;
	std::string getName() const;
	unsigned int getAge() const;
	double getSkills() const;
	std::string getBusinessCard() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};


int Person::counter = 0;

#endif // !_PERSON_H
