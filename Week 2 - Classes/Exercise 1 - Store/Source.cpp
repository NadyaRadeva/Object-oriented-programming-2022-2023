#include "Wafer.h"
#include "WaferStore.h"
#include<iostream>

int main()
{
	WaferStore store;
	store.initialiseStore(50);

	Wafer wafer{ "Borovec",0.05,1.50,0.80 };

	store.orderWafers(wafer, 30);
	store.printProfit();
	store.printShop();

	std::cout << " \nSelling 20 wafers..\n " << std::endl;
	for (int i = 1; i <= 20; i++)
		store.sellWafers();

	store.printProfit();
	store.printShop();
}