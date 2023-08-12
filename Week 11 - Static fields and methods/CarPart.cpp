#include "CarPart.h"
#include<iostream>

int CarPart::count = 0;

void CarPart::displayBase() const {
	std::cout << this->name << this->manufacturer << this->year << this->serialNumber;
}

int CarPart::getCarPartsCount() {
	return count;
}

CarPart::CarPart(std::string _name, std::string _manufacturer, unsigned int _year) {
	this->name = _name;
	this->manufacturer = _manufacturer;
	this->year = _year;

	this->serialNumber = count++;
}
