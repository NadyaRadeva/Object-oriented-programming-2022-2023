#ifndef _SHOE_H
#define _SHOE_H

#include<fstream>

class Shoe {
public:
	char* manufacturer;
	char* model;
	double price, rating;
	unsigned int availablePairs;

	void readData(std::ifstream& stream);
	void writeData(std::ofstream& stream);
};

#endif // !_SHOE_H

