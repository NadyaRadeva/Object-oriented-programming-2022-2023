#ifndef _TYRE_H
#define _TYRE_H

#include "CarPart.h"
#include<string>

class Tyre :public CarPart {
private:
	double width;
	unsigned int profile;
	unsigned int diameter;

public:
	Tyre(std::string _name, std::string _manufacturer, unsigned int _year, double _width, unsigned int _profile, unsigned int _diameter);
	void display() const override;
	CarPart* copy() const override;
};

#endif // !_TYRE_H
