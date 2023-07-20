#include "WaferStore.h"
#include<exception>
#include<iostream>

#include "Wafer.h"

void WaferStore::initialiseStore(int maxCountWafers) {
	if (maxCountWafers < 0)
		this->maxCountWafers = 20;
	else
	{
		this->maxCountWafers = maxCountWafers;
		this->countWafers = this->proceeds = this->expences = 0;
	}
}

void WaferStore::orderWafers(Wafer wafer, int count) {
	if (this->countWafers != 0)
		throw std::exception("Shop not empty");
	if (maxCountWafers < count || count < 1)
		throw std::exception("Not enough space");

	exampleWafer = wafer;
	this->countWafers = count;

	expences += wafer.factoryPrice * count;
}

void WaferStore::sellWafers() {
	if (countWafers == 0)
		throw std::exception("No wafers");
	countWafers--;
	proceeds += exampleWafer.clientPrice;
}

void WaferStore::printShop() {
	std::cout << countWafers << " wafers of brand " << exampleWafer.brand << std::endl;
	std::cout << "Total weight: " << exampleWafer.weight * countWafers << std::endl;
}

void WaferStore::printProfit() {
	std::cout << "Profit: " << proceeds - expences << std::endl;
}
