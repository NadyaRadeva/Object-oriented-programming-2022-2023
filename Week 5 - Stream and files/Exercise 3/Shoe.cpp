#include "Shoe.h"
#include<cstring>

void Shoe::readData(std::ifstream& stream) {
	std::getline(stream, model);
	std::getline(stream, producer);
	stream >> price >> rating >> pair_amount;
	stream.ignore();
}

void Shoe::writeData(std::ofstream& stream) {
	stream << model << std::endl;
	stream << manufacturer << std::endl;
	stream << price << std::endl;
	stream << rating << std::endl;
	stream << availablePairs << std::endl;
}
