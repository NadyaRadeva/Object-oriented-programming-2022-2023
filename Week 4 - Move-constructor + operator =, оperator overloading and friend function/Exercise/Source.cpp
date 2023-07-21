#include<iostream>
#include "Matrix.h"
#include<iomanip>

int main() {
	unsigned int rows1;
	std::cout << "Enter number of rows: ";
	std::cin >> rows1;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (rows1 <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	unsigned int cols1;
	std::cout << "Enter number of columns: ";
	std::cin >> cols1;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (cols1 <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	Matrix matrix1(rows1, cols1);
	print(matrix1);
	std::cout << std::endl;

	unsigned int rows2;
	std::cout << "Enter number of rows: ";
	std::cin >> rows2;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (rows2 <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	unsigned int cols2;
	std::cout << "Enter number of columns: ";
	std::cin >> cols2;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (cols2 <= 0) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	Matrix matrix2(rows2, cols2);
	print(matrix2);
	std::cout << std::endl;

	Matrix c = matrix1 + matrix2;
	std::cout << "Matrix 1 + Matrix 2 = " << std::endl;
	print(c);
	std::cout << std::endl;

	Matrix d = matrix1 - matrix2;
	std::cout << "Matrix 1 - Matrix 2 = " << std::endl;
	print(d);
	std::cout << std::endl;

	Matrix e = matrix1 * matrix2;
	std::cout << "Matrix 1 * Matrix 2 = " << std::endl;
	print(e);
	std::cout << std::endl;

	if (matrix1 == matrix2) {
		std::cout << "Matrix 1 and Matrix 2 are equal." << std::endl;
	}
	else {
		std::cout << "Matrix 1 and Matrix 2 are not equal." << std::endl;
	}

	std::cout << "Transpose matrix 1: ";
	transpose(matrix1);
	
}