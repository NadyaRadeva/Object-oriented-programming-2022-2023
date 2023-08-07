#include "Animal.h"
#include<cstring>

void Animal::copyName(const char* name1) {
	this->name = new char[strlen(name1) + 1];
	strcpy_s(this->name, strlen(name1) + 1, name1);
}

void Animal::copy(Animal const& other) {
	this->copyName(other.name);
	this->age = other.age;
}

void Animal::erase() {
	delete[] this->name;
}

Animal::Animal(char* _name, unsigned int _age) {
	copyName(_name);
	this->age = _age;
}

Animal::Animal(Animal const& other) {
	this->copy(other);
}

Animal Animal::operator=(Animal const& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

Animal::~Animal() {
	this->erase();
}

void Animal::print() {
	std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
}

void Animal::changeName(const char* name1) {

}
