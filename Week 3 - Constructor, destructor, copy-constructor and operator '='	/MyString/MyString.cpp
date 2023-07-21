#include "MyString.h"
#include <cstring>
#include <iostream>

void MyString::copy(const MyString& other) {
	this->size = other.size;

	if (other.empty()) {
		this->arr = nullptr;
	}
	else {
		this->arr = new char[size];
		for (size_t i = 0; i < size; ++i) {
			this->arr[i] = other.arr[i];
		}
	}
}

void MyString::erase() {
	delete[] this->arr;
}

MyString::MyString() {
	this->arr = nullptr;
	this->size = 0;
}

MyString::MyString(const char* str) {
	this->size = strlen(str);
	if (this->size == 0) {
		this->arr = nullptr;
	}
	else {
		this->arr = new char[size];
		for (size_t i = 0; i < size; ++i) {
			arr[i] = str[i];
		}
	}
}

MyString::MyString(const MyString& other) {
	this->copy(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

MyString::~MyString() {
	this->erase();
}

int MyString::length() {
	return this->size;
}

char& MyString::at(unsigned index) {
	if (index >= this->size) {
		throw std::exception("Invalid index!");
	}

	return arr[index];
}

int MyString::find(char c, unsigned startPosition) {
	for (size_t i = startPosition; i < size; ++i) {
		if (arr[i] == c) {
			return i;
		}
	}

	return -1;
}

bool MyString::empty() const {
	return size == 0;
}

MyString MyString::substr(unsigned position, unsigned n) {
	if (pos >= size)
		throw std::exception("Invalid index");

	if (n == 0)
		return MyString(); // създаваме и връщаме празен низ

	MyString ans;
	if (pos + n > size)
		ans.size = size - pos;
	else
		ans.size = n;

	ans.arr = new char[ans.size];

	for (int i = pos; i < pos + n && i < size; i++)
		ans.arr[i - pos] = arr[i];

	return ans;
}

void MyString::append(const MyString& str) {
	if (empty())
	{
		*this = str;
		return;
	}

	MyString temp;
	temp.size = size + str.size;
	temp.arr = new char[temp.size];

	for (size_t i = 0; i < size; i++) {
		temp.arr[i] = arr[i];
	}

	for (size_t i = 0; i < str.size; i++) {
		temp.arr[i + size] = str.arr[i];
	}

	*this = temp;
}

void MyString::print() {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i];
	}
}
