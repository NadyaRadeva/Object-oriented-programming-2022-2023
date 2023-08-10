#ifndef _VEHICLE_H
#define _VEHICLE_H

class Vehicle {
private:
	char* id;
	unsigned int seats;
	int speed;
	double rent;

public:
	Vehicle(char* _id, unsigned int _seats, int _speed, double _rent);
	virtual ~Vehicle();
	Vehicle(Vehicle const& other);
	Vehicle operator=(Vehicle const& other);
};

#endif // !_VEHICLE_H
