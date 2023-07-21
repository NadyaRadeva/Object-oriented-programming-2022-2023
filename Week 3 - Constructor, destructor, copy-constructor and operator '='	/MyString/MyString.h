#ifndef _MYSTRING_H
#define _MYSTRING_H

class MyString {
private:
	unsigned int size;
	char* arr;

	void copy(const MyString& other);
	void erase();

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	int length();
	char& at(unsigned index);
	int find(char c, unsigned startPosition = 0);
	bool empty() const;
	MyString substr(unsigned position = 0, unsigned n = 0);
	void append(const MyString& str);
	void print();

};

#endif // !_MYSTRING_H
