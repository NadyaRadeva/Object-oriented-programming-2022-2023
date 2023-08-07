#ifndef _ANIMAL_H
#define _ANIMAL_H

class Animal {
private:
	char* name;
	unsigned int age;

	void copyName(const char* name1);
	void copy(Animal const& other);
	void erase();

public:
	Animal(char* _name, unsigned int _age);
	Animal(Animal const& other);
	Animal operator=(Animal const& other);
	~Animal();

	void print();
	void changeName(const char*);
};

#endif // !_ANIMAL_H
