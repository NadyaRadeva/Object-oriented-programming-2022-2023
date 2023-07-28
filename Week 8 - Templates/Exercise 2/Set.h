#ifndef _SET_H
#define _SET_H

#include<iostream>

template<typename T>
class Set {
private:
	int capacity, size;
	T* arr;

	void copy(Set<T> const& other);
	void erase();
	void resize();

public:
	Set();
	Set(Set<T> const& other);
	Set<T>& operator=(Set<T> const& other);
	~Set();

	void add(const T& other);
	bool isEmpty();
	void print();
	bool contains(const T& other);

	Set<T> operator+(const Set<T>& other);
	bool operator<(const Set<T>& other);
};

template<typename T>
void Set<T>::copy(Set<T> const& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->arr = new T[capacity];
	for (size_t i = 0; i < size; ++i) {
		this->arr[i] = other.arr[i];
	}
}

template<typename T>
void Set<T>::erase() {
	delete[] this->arr;
}

template<typename T>
void Set<T>::resize() {
	this->capacity *= 2;
	T* newArr = new T[this->capacity];
	for (size_t i = 0; i < this->size; ++i) {
		newArr[i] = this->arr[i];
	}
	delete[] this->arr[i];
	this->arr = newArr;
}

template<typename T>
Set<T>::Set() {
	const int initCap = 8;
	this->arr = new T[initCap];
	this->capacity = initCap;
	this->size = 0;
}

template<typename T>
Set<T>::Set(Set<T> const& other) {
	this->copy(other);
}

template<typename T>
Set<T>& Set<T>:: operator=(Set<T> const& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

template<typename T>
Set<T>::~Set() {
	this->erase();
}

template<typename T>
void Set<T>::add(const T& other) {
	if (!contains(other)) {
		if (this->capacity == this->size) {
			this->resize();

			this->arr[this->size] = other;
			this->size++;
		}
	}
}

template<typename T>
bool Set<T>::isEmpty() {
	return this->size == 0;
}

template<typename T>
void Set<T>::print() {
	for (size_t i = 0; i < this->size; ++i) {
		std::cout << this->arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
bool Set<T>::contains(const T& other) {
	for (size_t i = 0; i < this->size; ++i) {
		if (this->arr[i] == other) {
			return true;
		}
	}

	return false;
}

template<typename T>
Set<T> Set<T>::operator+(const Set<T>& other) {
	Set<T> c(b);
	for (size_t i = 0; i < this->size; ++i) {
		c.add(this->arr[i]);
	}

	return c;
}

template<typename T>
bool Set<T>::operator<(const Set<T>& other) {
	for (size_t i = 0; i < this->size; ++i) {
		if (!b.contains(arr[i])) {
			return false;
		}
	}

	return true;
}

#endif // !_SET_H
