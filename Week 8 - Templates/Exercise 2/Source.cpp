#include<iostream>
#include "Set.h"

int main() {
	Set<int> s1, s2;
	for (size_t i = 0; i <= 10; ++i) {
		s1.add(i);
	}

	s1.add(2);
	s1.add(2);
	s1.add(2);

	s1.print();

	for (size_t i = 5; i < 15; ++i) {
		s2.add(i);
	}

	s2.print();

	Set<int> s3;
	s3 = s1 + s2;

	s3.print();

	std::cout << (s1 < s3) << std::endl;
}