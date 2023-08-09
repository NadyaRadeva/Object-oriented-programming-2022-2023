#include "Triangle.h"
#include<iostream>

Triangle::Triangle(std::string _label, double _sideA, double _sideB, double _sideC): Shape(_label) {
	this->sideA = _sideA;
	this->sideB = _sideB;
	this->sideC = _sideC;
}

double Triangle::getPerimeter() {
	return this->sideA + this->sideB + this->sideC;
}

void Triangle::print() {
	std::cout << " /\\" << std::endl;
	std::cout << "/_\\" << std::endl;
}

Shape* Triangle::copy() const {
	return new Triangle(*this);
}
