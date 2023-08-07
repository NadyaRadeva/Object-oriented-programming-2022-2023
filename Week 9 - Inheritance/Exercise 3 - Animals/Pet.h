#ifndef _PET_H
#define _PET_H

#include "Animal.h"

class Pet : public Animal {
private:
	char* ownerName;
	unsigned int phoneNumber;

	void copyName(const char* name1);
	void copy(Pet const* other);
	void erase();

public:
	Pet(char* _name, unsigned int _age, char* _ownerName, unsigned int _phoneNumber);
	Pet(Pet const& other);
	Pet operator=(Pet const& other);
	~Pet();
	
	void print();
	void changeOwner(const char* name1, unsigned int number);
};


#endif // !_PET_H
