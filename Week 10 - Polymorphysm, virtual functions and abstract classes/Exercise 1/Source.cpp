#include<iostream>
#include "Triangle.h"

int main() {
	Triangle tr1("triangle", 2, 3, 4);
	tr1.print();
	std::cout << "Perimeter: " << tr1.getPerimeter() << std::endl;
}