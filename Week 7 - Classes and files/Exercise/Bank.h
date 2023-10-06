#include "Account.h"

#ifndef BANK_H
#define BANK_H

class Bank {
private:
	Account** accounts;
	size_t capacity, count, current_id;

	void copy(const Bank& other);
	void erase();

	void resize();

	int findIndex(size_t id);
	void sortArr(Account** arr,int size);

public:
	Bank();
	Bank(const Bank&);
	Bank& operator=(const Bank&);
	~Bank();

	int openAccount(std::string new_owner);
	void Withdrawal(size_t id, double amount);
	void Deposit(size_t id, double amount);
	void Transfer(size_t from, size_t to, double amount);
	void print();
};

#endif
