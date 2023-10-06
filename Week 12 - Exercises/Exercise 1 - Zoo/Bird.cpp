#include "Bird.h"

int Bird::eat() const {
    return weight / 10 + numberOfEggs;
}

Food Bird::getFoodType() const {
    return this->foodType;
}

Bird::Bird(const char *name, int weight, Food foodType, int numberOfEggs, const std::string& nameOfNestCity) : Animal(name, weight, foodType) {
    this->numberOfEggs = numberOfEggs;
    this->nameOfNestCity = nameOfNestCity;
}
