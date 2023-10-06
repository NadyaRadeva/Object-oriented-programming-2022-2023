#include "Shape.h"

Shape::Shape(const std::string& label1) : label(label1) {
}

const std::string& Shape::getLabel() {
	return label;
}

Shape::~Shape() {
}
