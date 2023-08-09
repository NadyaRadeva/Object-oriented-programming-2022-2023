#ifndef _CIRCLE_H
#define _CIRCLE_H

#include<iostream>
#include<string>
#include "Shape.h"

class Circle: public Shape {
private:
	double radius;

public:
	Circle(std::string _label, double _radius);
	double getPerimeter() override;
	void print() override;
	Shape* copy() const override;
};

#endif // !_CIRCLE_H
