#include "Engine.h"
#include "CarPart.h"
#include<iostream>

Engine::Engine(std::string _name, std::string _manufacturer, unsigned int _year, int _hp):CarPart(_name,_manufacturer,_year){
	this->hp = _hp;
}

void Engine::addPiston(Piston const& piston) {
	pistons.push_back(piston);
}

void Engine::display() const {
	this->displayBase();
	std::cout << this->hp;
	for (size_t i = 0; i < pistons.size(); ++i) {
		pistons[i].display();
	}
}

CarPart* Engine::copy() const {
	return new Engine(*this);
}
