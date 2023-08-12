#ifndef _PISTON_H
#define _PISTON_H

#include "CarPart.h"

class Piston :public CarPart {
private:
	double diameter;
	double range;

public:
	Piston(std::string _name, std::string _manufacturer, unsigned int _year, double _diameter, double _range);
	void display() const override;
	CarPart* copy() const override;
};

#endif // !_PISTON_H