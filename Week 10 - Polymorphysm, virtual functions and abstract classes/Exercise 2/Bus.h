#ifndef _BUS_H
#define _BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
private:
	unsigned int bootCapacity;

public:
	Bus(char* _id, unsigned int _seats, int _speed, double _rent, unsigned int _bootCapacity);
	~Bus() override;
	Bus(Bus const& other);
	Bus operator=(Bus const& other);
};

#endif // !_BUS_H
