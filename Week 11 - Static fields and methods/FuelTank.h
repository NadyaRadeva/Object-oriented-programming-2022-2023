#ifndef _FUELTANK_H
#define _FUELTANK_H

#include "CarPart.h"
#include<iostream>

template<typename T>
class FuelTank : public CarPart {
private:
	T fuelType;
	int volume;

public:
	FuelTank(std::string _name, std::string _manufacturer, unsigned int _year, T _fuelType, int _volume);
	void display() const override;
	CarPart* copy() const override;
};

#endif // !_FUELTANK_H

template<typename T>
inline FuelTank<T>::FuelTank(std::string _name, std::string _manufacturer, unsigned int _year, T _fuelType, int _volume):CarPart(_name,_manufacturer,_year) {
	this->fuelType = _fuelType;
	this->volume = _volume;
}

template<typename T>
inline void FuelTank<T>::display() const {
	this->displayBase;
	std::cout << this->fuelType << this->volume << std::endl;
}

template<typename T>
inline CarPart* FuelTank<T>::copy() const {
	return new FuelTank<T>(*this);
}
