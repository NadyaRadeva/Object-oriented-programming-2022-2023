#include "Piston.h"
#include<iostream>

Piston::Piston(std::string _name, std::string _manufacturer, unsigned int _year, double _diameter, double _range):CarPart(_name,_manufacturer,_year) {
	this->diameter = _diameter;
	this->range = _range;
}

void Piston::display() const {
	this->displayBase();
	std::cout << this->diameter << this->range << std::endl;
}

CarPart* Piston::copy() const {
	return new Piston(*this);
}
