#include<iostream>

template <typename T>
void swap(T a, T b) {
	T c;
	c = a;
	a = b;
	b = c;
}

int main() {
	int num1 = 2, num2 = 1;
	swap(num1, num2);
	std::cout << num1 << " " << num2 << std::endl;
}