#include "Person.h"

Person::Person(std::string _name, unsigned int _age, std::string _businessCard, double _skills) {
	this->name = _name;
	this->age = _age;
	this->businessCard = _businessCard;
	this->skills = _skills;
	this->id = counter++;
}

unsigned Person::getId() const {
	return this->id;
}

std::string Person::getName() const {
	return this->name;
}

unsigned int Person::getAge() const {
	return this->age;
}

double Person::getSkills() const {
	return this->skills;
}

std::string Person::getBusinessCard() const {
	return this->businessCard;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
	std::cout << "Hello, I'm " << p.name << " with id: " << p.id << ". I'm " << p.age << " years old. My skills are " << p.skills << " and here is my business card: " << p.businessCard << "." << std::endl;
	return os;
}
