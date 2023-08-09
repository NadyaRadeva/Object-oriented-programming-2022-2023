#include "Square.h"
#include "Shape.h"
#include<iostream>
#include<string>

Square::Square(std::string _label, double _side): Shape(_label) {
	this->side = _side;
}

double Square::getPerimeter() {
	return 4 * this->side;
}

void Square::print() {
	std::cout << " ___" << std::endl;
	std::cout << "|   |" << std::endl;
	std::cout << "|___|" << std::endl;
	std::cout << std::endl;
}

Shape* Square::copy() const  {
	Shape* ptr = new Square(*this);
	return ptr;
}
