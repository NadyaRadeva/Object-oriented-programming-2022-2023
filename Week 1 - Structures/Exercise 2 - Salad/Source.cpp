#include<iostream>
#include<cstring>

const int MAX_LEN = 21;

struct Vegetable {
	char vegetableName[MAX_LEN];
	double weight;

	void inputVegetable() {
		std::cout << "Vegetable name: ";
		std::cin.getline(vegetableName, MAX_LEN);

		std::cout << "Vegetable weight: ";
		std::cin >> weight;
		std::cin.ignore();
	}
};

struct Dressing {
	char* dressingName;
	double quantity;
	char allergen[MAX_LEN];

	void inputDressing() {
		std::cout << "Dressing name: ";
		std::cin.getline(dressingName, MAX_LEN);

		std::cout << "Dressing quantity: ";
		std::cin >> quantity;
		std::cin.ignore();

		std::cout << "Allergen name: ";
		std::cin.getline(allergen, MAX_LEN);
	}
};

struct Salad {
	char saladName[MAX_LEN];
	Vegetable vegetables[3];
	Dressing saladDressing;
	double price;

	void inputSalad() {
		std::cout << "Salad name: ";
		std::cin.getline(saladName, MAX_LEN);

		for (size_t i = 0; i < 3; ++i) {
			vegetables[i].inputVegetable();
		}

		saladDressing.inputDressing();

		std::cout << "Salad price: ";
		std::cin >> price;
		std::cin.ignore();
	}

	double getWeight()
	{
		double ans = 0;
		for (int i = 0; i < 3; i++)
			ans += vegetables[i].weight;
		return ans;
	}

	void printAllergen()
	{
		std::cout << saladDressing.allergen;
	}

	void print()
	{
		std::cout << saladName << std::endl;

		std::cout << "Contents: ";
		for (int i = 0; i < 3; i++)
			std::cout << vegetables[i].vegetableName << " ";
		std::cout << saladDressing.dressingName << std::endl;

		std::cout << "Price: " << price << std::endl;
		std::cout << "Weight: " << getWeight() << std::endl;
		std::cout << "Allergen: " << saladDressing.allergen << std::endl;
	}
};

void analyseSalads(Salad salads[], int n)
{
	std::cout << "Salads: ";

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << salads[i].saladName << " ";
		sum += salads[i].price;
	}
	std::cout << std::endl;

	std::cout << "Total cost: " << sum << std::endl;

	std::cout << "Allergens: ";
	for (int i = 0; i < n; i++)
	{
		salads[i].printAllergen();
		std::cout << ", ";
	}
	std::cout << std::endl;
}

int main() {
	Salad salad1;
	salad1.inputSalad();
	std::cout << std::endl;
	salad1.print();


	Salad salad_arr[5];
	for (int i = 0; i < 5; i++)
		salad_arr[i].inputSalad();

	analyseSalads(salad_arr, 5);

	return 1;
}