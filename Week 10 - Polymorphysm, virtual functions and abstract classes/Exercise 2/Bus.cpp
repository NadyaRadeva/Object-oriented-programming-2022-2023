#include "Bus.h"

Bus::Bus(char* _id, unsigned int _seats, int _speed, double _rent, unsigned int _bootCapacity):Vehicle(_id,_seats,_speed,_rent,_bootCapacity) {
	this->bootCapacity = _bootCapacity;
}

Bus::~Bus() {
}

Bus::Bus(Bus const& other): Vehicle(other) {
	this->bootCapacity = other.bootCapacity;
}

Bus Bus::operator=(Bus const& other) {
	if (this != &other) {
		Vehicle::operator=(other);

		this->bootCapacity = other.bootCapacity;
	}

	return *this;
}
