#ifndef _TRIANGLE_H
#define _TRIANGLE_H

class Triangle {
private:
	double a, b, c;

public:
	Triangle(double a, double b, double c);

	bool isTriangleRight();
	bool isTriangleEquilateral();
	double findPerimeter();
	double findHalfPerimeter();
	double findSurfaceArea();
	double findAltitude(double side);
	double findRadiusOfIncircle();
	double findRadiusOfExcircle();

};

#endif // !_TRIANGLE_H
