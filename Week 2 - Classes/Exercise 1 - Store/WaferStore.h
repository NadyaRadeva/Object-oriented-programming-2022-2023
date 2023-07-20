#ifndef _WAFERSTORE_H
#define _WAFERSTORE_H

#include "Wafer.h"

class WaferStore {
private:
	Wafer exampleWafer;
	int countWafers, maxCountWafers;
	double proceeds, expences;

public:
	void initialiseStore(int maxCountWafers);
	void orderWafers(Wafer wafer, int count);
	void sellWafers();
	void printShop();
	void printProfit();
};

#endif // !_WAFERSTORE_H
