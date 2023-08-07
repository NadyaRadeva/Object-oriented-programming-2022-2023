#include "Pet.h"
#include<cstring>
#include "Animal.h"

void Pet::copyName(const char* _ownerName) {
	int len = strlen(_ownerName);
	this->ownerName = new char[len + 1];
	strcpy_s(this->ownerName, len, _ownerName);
}

void Pet::copy(Pet const* other) {
	this->copyName(other->ownerName);
	this->phoneNumber = other->phoneNumber;
}

void Pet::erase() {
	delete[] this->ownerName;
}

Pet::Pet(char* _name, unsigned int _age, char* _ownerName, unsigned int _phoneNumber): Animal(_name,_age) {
	this->copyName(_ownerName);
	this->phoneNumber = _phoneNumber;
}

Pet::Pet(Pet const& other): Animal(other) {
	this->copy(other);

}

Pet Pet::operator=(Pet const& other) {
	if (this != &other) {
		Animal::operator=(other);
		this->erase();
		this->copy(other);
	}
}

Pet::~Pet() {
	this->erase();
}

void Pet::print()
{
	Animal::print();
	std::cout << "Owner name: " << this->ownerName << ", Phone number: " << this->phoneNumber << std::endl;
}

void Pet::changeOwner(const char* name1, unsigned number)
{
	erase();
	copyName(name1);
	phone_number = number;
}
