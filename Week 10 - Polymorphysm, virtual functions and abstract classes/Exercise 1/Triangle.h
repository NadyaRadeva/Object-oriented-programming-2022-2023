#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Shape.h"
#include<iostream>
#include<string>

class Triangle : public Shape {
private:
	double sideA, sideB, sideC;

public:
	Triangle(std::string _label, double _sideA, double _sideB, double _sideC);
	double getPerimeter() override;
	void print() override;
	Shape* copy() const override;
};

#endif // !_TRIANGLE_H
