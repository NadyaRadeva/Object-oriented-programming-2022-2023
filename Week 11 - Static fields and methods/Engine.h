#ifndef _ENGINE_H
#define _ENGINE_H

#include "CarPart.h"
#include<vector>
#include "Piston.h"

class Engine :public CarPart {
private:
	int hp;
	std::vector<Piston> pistons;

public:
	Engine(std::string _name, std::string _manufacturer, unsigned int _year, int _hp);
	void addPiston(Piston const& piston);
	void display() const override;
	CarPart* copy() const override;
};


#endif // !_ENGINE_H
