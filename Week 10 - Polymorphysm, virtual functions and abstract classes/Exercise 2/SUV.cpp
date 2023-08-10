#include "SUV.h"
#include "Vehicle.h"

SUV::SUV(char* _id, unsigned int _seats, int _speed, double _rent, bool is4X4): Vehicle(_id,_seats,_speed,_rent) {
	this->is4X4 = is4X4;
}

SUV::~SUV() {
	
}

SUV::SUV(SUV const& other): Vehicle(other) {
	this->is4X4 = other.is4X4;
}

SUV SUV::operator=(SUV const& other) {
	if (this != &other) {
		Vehicle::operator=(other);
		
		this->is4X4 = other.is4X4;
	}

	return *this;
}
