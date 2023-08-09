#include "Shape.h"

Shape::Shape(std::string _label) {
	this->label = _label;
}

const std::string& Shape::getLabel() {
	return this->label;
}

Shape::~Shape() {
}
