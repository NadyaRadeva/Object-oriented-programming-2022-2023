#ifndef _CARPART_H
#define _CARPART_H

#include<string>

class CarPart {
protected:
	std::string name;
	std::string manufacturer;
	unsigned int year;
	int serialNumber;
	static int count;

protected:
	void displayBase() const;

public:
	static int getCarPartsCount();
	virtual void display() const = 0;
	virtual CarPart* copy() const = 0;

	CarPart(std::string _name, std::string _manufacturer, unsigned int _year);
	virtual ~CarPart() = default;
};

#endif // !_CARPART_H
