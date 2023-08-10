#ifndef _CAR_H
#define _CAR_H

#include "Vehicle.h"

class Car :public Vehicle {
private:
	char* brand;

public:
	Car(char* _id, unsigned int _seats, int _speed, double _rent, char* _brand);
	~Car() override;
	Car(Car const& other);
	Car operator=(Car const& other);
};

#endif // !_CAR_H
