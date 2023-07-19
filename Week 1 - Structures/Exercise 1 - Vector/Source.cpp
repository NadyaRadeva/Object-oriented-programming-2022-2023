#include<iostream>
#include<cmath>
#include<iomanip>

struct Vector3D{
	double x, y, z;

	double getVectorLength(Vector3D vector) {
		return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	}

	Vector3D plus(Vector3D vector) {
		Vector3D sum;
		sum.x = x + vector.x;
		sum.y = y + vector.y;
		sum.z = z + vector.z;
	}

	void printVector(Vector3D vector) {
		std::cout << "X= " << vector.x << " " << "Y= " << vector.y << " " << "Z= " << vector.z << std::endl;
	}
};

double getScalarProduct(Vector3D first, Vector3D second) {
	return first.x * second.x + first.y * second.y + first.z * second.z;
}

bool arePerpendicular(Vector3D first, Vector3D second) {
	if (getScalarProduct(first, second) == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	std::cout << "Vector 1: " << std::endl;
	double x1;
	std::cout << "Enter value of X: ";
	std::cin >> x1;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	double y1;
	std::cout << "Enter value of Y: ";
	std::cin >> y1;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	double z1;
	std::cout << "Enter value of Z: ";
	std::cin >> z1;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	std::cout << "Vector 2: " << std::endl;
	double x2;
	std::cout << "Enter value of X: ";
	std::cin >> x2;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	double y2;
	std::cout << "Enter value of Y: ";
	std::cin >> y2;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	double z2;
	std::cout << "Enter value of Z: ";
	std::cin >> z2;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	Vector3D vector1;
	vector1.x = x1;
	vector1.y = y1;
	vector1.z = z1;

	Vector3D vector2;
	vector2.x = x2;
	vector2.y = y2;
	vector2.z = z2;

	std::cout << "Scalar product of the two vectors: " << getScalarProduct(vector1, vector2) << std::endl;
	std::cout << "Are they perpendicular? - " << std::boolalpha << arePerpendicular(vector1, vector2) << std::endl;

	std::cout << "Lenght: " << vector1.getVectorLength(vector1) << std::endl;

	Vector3D vector3;
	vector3 = vector1.plus(vector2);

	vector3.printVector(vector3);

	return 1;
}
