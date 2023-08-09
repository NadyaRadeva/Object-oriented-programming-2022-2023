#ifndef _SQUARE_H
#define _SQUARE_H

#include<string>

class Square : public Shape {
private:
	double side;

public:
	Square(std::string _label, double _side);
	double getPerimeter() override;
	void print() override;
	Shape* copy() const override;
};

#endif // !_SQUARE_H
