#include<iostream>
#include<iomanip>

#include "Triangle.h"

int main() {
	std::cout << "Enter side A: ";
	double sideA;
	std::cin >> sideA;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (sideA <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	std::cout << "Enter side B: ";
	double sideB;
	std::cin >> sideB;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (sideB <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	std::cout << "Enter side C: ";
	double sideC;
	std::cin >> sideC;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (sideC <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	Triangle tr(sideA, sideB, sideC);

	std::cout << "Is the triangle right? - " << std::boolalpha << tr.isTriangleRight() << std::endl;
	std::cout << "Is the triangle equilateral? - " << std::boolalpha << tr.isTriangleEquilateral() << std::endl;
	std::cout << "Half-perimeter: " << tr.findHalfPerimeter() << std::endl;
	std::cout << "Perimeter: " << tr.findPerimeter() << std::endl;
	std::cout << "Surface area: " << tr.findSurfaceArea() << std::endl;
	std::cout << "Altitude to side A: " << tr.findAltitude(sideA) << " Altitude to side B: " << tr.findAltitude(sideB) << " Altitude to side C: " << tr.findAltitude(sideC) << std::endl;
	std::cout << "Radius of incircle: " << tr.findRadiusOfIncircle() << std::endl;
	std::cout << "Radius of excircle: " << tr.findRadiusOfExcircle();

	return 1;
}