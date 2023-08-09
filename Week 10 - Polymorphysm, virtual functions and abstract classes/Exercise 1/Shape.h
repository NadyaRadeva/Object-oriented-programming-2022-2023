#ifndef _SHAPE_H
#define _SHAPE_H

#include<string>

class Shape {
private:
	std::string label;

public:
	Shape(std::string _label);
	const std::string& getLabel();
	virtual Shape* copy() const = 0;
	virtual void print();
	virtual double getPerimeter();

	virtual ~Shape();
};

#endif // !_SHAPE_H

