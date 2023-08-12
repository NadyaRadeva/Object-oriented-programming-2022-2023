#include "Tyre.h"
#include<iostream>

Tyre::Tyre(std::string _name, std::string _manufacturer, unsigned int _year, double _width, unsigned int _profile, unsigned int _diameter):CarPart(_name,_manufacturer,_year) {
	this->width = _width;
	this->profile = _profile;
	this->diameter = _diameter;
}

void Tyre::display() const {
	this->displayBase();
	std::cout << this->width << this->profile << this->diameter << std::endl;
}

CarPart* Tyre::copy() const {
	return new Tyre(*this);
}
