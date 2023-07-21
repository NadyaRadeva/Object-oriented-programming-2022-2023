#include "Triangle.h"
#include<cmath>

Triangle::Triangle(double a, double b, double c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

bool Triangle::isTriangleRight() {
	if (pow(this->a, 2) + pow(this->b, 2) == pow(this->c, 2) || pow(this->b,2) + pow(this->c,2) == pow(this->a,2) || pow(this->c,2) + pow(this->a,2) == pow(this->b,2)) {
		return true;
	}
	else {
		return false;
	}
}

bool Triangle::isTriangleEquilateral() {
	if (this->a == this->b || this->a == this->c || this->b == this->c) {
		return true;
	}
	else {
		return false;
	}
}

double Triangle::findPerimeter() {
	return this->a + this->b + this->c;
}

double Triangle::findHalfPerimeter() {
	return findPerimeter() / 2;
}

double Triangle::findSurfaceArea() {
	
	return sqrt(findHalfPerimeter() * (findHalfPerimeter() - this->a) * (findHalfPerimeter() - this->b) * (findHalfPerimeter() - this->c));
}

double Triangle::findAltitude(double side) {
	if (isTriangleEquilateral() && (this->a == side || this->b == side || this->c == side)) {
		return 2 * (findSurfaceArea() / findHalfPerimeter());
	}
	else {
		return 2 * findSurfaceArea() / side;
	}
}

double Triangle::findRadiusOfIncircle() {
	return findSurfaceArea() / findHalfPerimeter();
}

double Triangle::findRadiusOfExcircle() {
	return (this->a * this->b * this->c) / findSurfaceArea();
}
