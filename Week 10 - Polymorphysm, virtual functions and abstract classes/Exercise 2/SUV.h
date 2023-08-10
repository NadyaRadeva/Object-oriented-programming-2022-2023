#ifndef _SUV_H
#define _SUV_H

#include "Vehicle.h"

class SUV :public Vehicle {
private:
	bool is4X4;

public:
	SUV(char* _id, unsigned int _seats, int _speed, double _rent, bool is4X4);
	~SUV();
	SUV(SUV const& other);
	SUV operator=(SUV const& other);
};

#endif // !_SUV_H
