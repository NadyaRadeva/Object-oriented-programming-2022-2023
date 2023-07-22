﻿#ifndef SHOESHOP_H
#define SHOESHOP_H

﻿#include "Shoe.h"

class ShoeShop
{
	size_t cur_amount, max_amount;
	Shoe* shoes;

	void copy(const ShoeShop& other);
	void erase();
	int findIndex(std::string model);

public:
	ShoeShop(size_t max_amount);
	ShoeShop(const ShoeShop&);
	ShoeShop& operator= (const ShoeShop&);
	~ShoeShop();

	void addModel(const Shoe& shoe);
	void sellPair(std::string model);
	void addAmount(std::string model, int amount);
	void changeRating(std::string model, double new_rating);
	void removeModel(std::string model);
	
	void readData(std::ifstream& stream);
	void writeData(std::ofstream& stream);
};

#endif