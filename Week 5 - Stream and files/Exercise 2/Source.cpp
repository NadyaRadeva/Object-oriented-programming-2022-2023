#include<iostream>
#include<fstream>

int main() {
	std::fstream iFile("Self-printing.cpp");
	if (iFile.is_open()) {
		std::cout << "Error occured while opening the file!" << std::endl;
		return 1;
	}

	char c;
	while (!iFile.eof()) {
		iFile.get(c);
		std::cout << c;
	}

	iFile.close();
	return 0;
}