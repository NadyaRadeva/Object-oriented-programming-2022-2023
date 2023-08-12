#ifndef _CAR_H
#define _CAR_H

#include<string>
#include "CarPart.h"

class Car {
private:
	std::string brand;
	std::string model;
	unsigned int size, capacity;
	CarPart** container;

	void copy(Car const& other);
	void resize();
	void erase();

public:
	void addCarPart(CarPart const& shape);
	void printParts();

	Car();
	Car(Car const& other);
	Car& operator=(Car const& other);
	~Car();
};

#endif // !_CAR_H
