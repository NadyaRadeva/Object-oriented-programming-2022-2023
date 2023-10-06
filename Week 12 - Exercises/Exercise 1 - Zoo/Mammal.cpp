#include "Mammal.h"

int Mammal::eat() const {
    return 4;
}

Food Mammal::getFoodType() const {
    return this->foodType;
}

Mammal::~Mammal() {
  delete[] this->nameOfAdopter;
}

Mammal::Mammal(const char *name, int weight, Food foodType, const char *nameOfAdopter)  :
Animal(name, weight, foodType){
    this->nameOfAdopter = new char[strlen(nameOfAdopter) + 1];
    strcpy(this->nameOfAdopter, nameOfAdopter);
}

Mammal::Mammal(const Mammal &other) : Animal(other){
    this->nameOfAdopter =  new char[strlen(other.nameOfAdopter) + 1];
    strcpy(this->nameOfAdopter, other.nameOfAdopter);
}

Mammal::Mammal(Mammal &&other)  noexcept : Animal(other){
    this->nameOfAdopter = other.nameOfAdopter;
    other.nameOfAdopter = nullptr;
}

Mammal &Mammal::operator=(const Mammal &other) {
    if (this != &other) {
        Animal::operator=(other);
        this->nameOfAdopter = new char[strlen(other.nameOfAdopter) + 1];
        strcpy(this->nameOfAdopter, other.nameOfAdopter);
    }
    return *this;
}

Mammal &Mammal::operator=(Mammal &&other)  noexcept {
    if (this != &other) {
        Animal::operator=(other);
        this->nameOfAdopter = other.nameOfAdopter;
        other.nameOfAdopter = nullptr;
    }
    return *this;
}
