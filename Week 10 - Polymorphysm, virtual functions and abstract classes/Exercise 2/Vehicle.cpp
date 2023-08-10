#include "Vehicle.h"
#include<cstring>

Vehicle::Vehicle(char* _id, unsigned int _seats, int _speed, double _rent) {
	this->id = new char[strlen(_id) + 1];
	strcpy_s(this->id, strlen(_id) + 1, _id);
	this->seats = _seats;
	this->speed = _speed;
	this->rent = _rent;
}

Vehicle::~Vehicle() {
	delete[] this->id;
}

Vehicle::Vehicle(Vehicle const& other) {
	this->id = new char[strlen(other.id) + 1];
	strcpy_s(this->id, strlen(other.id) + 1, other.id);
	this->seats = other.seats;
	this->speed = other.speed;
	this->rent = other.rent;
}

Vehicle Vehicle::operator=(Vehicle const& other) {
	if (this != &other) {
		delete[] id;

		this->id = new char[strlen(other.id) + 1];
		strcpy_s(this->id, strlen(other.id) + 1, other.id);
		this->seats = other.seats;
		this->speed = other.speed;
		this->rent = other.rent;
	}

	return *this;
}
