#include<fstream>
#include<iostream>

int fileLength(const char* fileName) {
	std::ifstream iFile(fileName);

	if (!iFile.is_open()) {
		return -1;
	}

	int length = -1;
	while (!iFile.eof()) {
		char c;
		iFile.get(c);
		length++;
	}

	iFile.close();
	return length;
}

int main() {
	std::cout << fileLength("File.txt") << std::endl;
}