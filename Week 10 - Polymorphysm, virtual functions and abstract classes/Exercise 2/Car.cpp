#include "Car.h"
#include<cstring>

Car::Car(char* _id, unsigned int _seats, int _speed, double _rent, char* _brand):Vehicle(_id,_seats,_speed,_rent) {
	this->brand = new char[strlen(_brand) + 1];
	strcpy_s(this->brand, strlen(_brand) + 1, _brand);
}

Car::~Car() {
	delete[] brand;
}

Car::Car(Car const& other):Vehicle(other) {
	this->brand = new char[strlen(other.brand) + 1];
	strcpy_s(this->brand, strlen(other.brand) + 1, other.brand);
}

Car Car::operator=(Car const& other) {
	if(this!=&other) {
		Vehicle::operator=(other);

		delete[] brand;

		this->brand = new char[strlen(other.brand) + 1];
		strcpy_s(this->brand, strlen(other.brand) + 1, other.brand);
	}

	return *this;
}
