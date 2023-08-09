#include "Circle.h"
#include<iostream>
#include<string>

Circle::Circle(std::string _label, double _radius): Shape(_label) {
	this->radius = _radius;
}

double Circle::getPerimeter() {
	return 2 * 3.13 * this->radius;
}

void Circle::print() {
	std::cout << " _ " << std::endl;
	std::cout << "/  \\" << std::endl;
	std::cout << "| |" << std::endl;
	std::cout << "\\  /" << std::endl;
	std::cout << " - " << std::endl;
}

Shape* Circle::copy() const {
	return new Circle(*this);
}

