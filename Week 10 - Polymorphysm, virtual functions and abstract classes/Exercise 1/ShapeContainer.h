#ifndef _SHAPECONTAINER_H
#define _SHAPECONTAINER_H

#include<iostream>
#include<vector>
#include "Shape.h"

class ShapeContainer {
private:
	std::vector <Shape*> container;

	void copy(Shape const& other);
	void erase();

public:
	void addShape(const Shape& shape);
	void printPerimeters();
	void printShapes();

	ShapeContainer();
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();
};

#endif // !_SHAPECONTAINER_H
