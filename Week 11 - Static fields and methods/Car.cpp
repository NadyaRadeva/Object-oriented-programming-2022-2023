#include "Car.h"
#include<iostream>

void Car::copy(Car const& other) {
	this->brand = other.brand;
	this->model = other.model;
	this->size = other.size;
	this->capacity = other.capacity;

	container = new CarPart * [other.capacity];
	for (size_t i = 0; i < other.size; ++i) {
		this->container[i] = other.container[i]->copy();
	}
}

void Car::resize() {
	this->capacity *= 2;
	CarPart** newContainer = new CarPart * [capacity];
	for (size_t i = 0; i < this->size; ++i) {
		newContainer[i] = this->container[i];
	}

	delete[] this->container;
	this->container = newContainer;
}

void Car::erase() {
	for (size_t i = 0; i < size; ++i) {
		delete this->container[i];
	}

	delete[] this->container;
}

void Car::addCarPart(CarPart const& part) {
	if (this->size == this->capacity) {
		resize();
	}

	this->container[size] = part.copy();
	this->size++;
}

void Car::printParts() {
	std::cout << "Parts: \n";
	for (size_t i = 0; i < this->size; ++i) {
		container[i]->display();
		std::cout << std::endl;
	}
}

Car::Car() {
	this->size = 0;
	this->capacity = 0;
	this->model = nullptr;
	this->brand = nullptr;
	this->container = new CarPart * [capacity];
}

Car::Car(Car const& other) {
	this->copy(other);
}

Car& Car::operator=(Car const& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

Car::~Car() {
	this->erase();
}
