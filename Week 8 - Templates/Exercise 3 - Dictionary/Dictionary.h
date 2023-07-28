#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include<exception>
#include<utility>
#include<iostream>

constexpr int MAX_SIZE = 200;

template<typename Key, typename Value>
class Dictionary {
private:
	std::pair<Key, Value> data[MAX_SIZE];
	int size;

public:
	Dictionary(): size(0){}

	void add(const Key& key, const Value& value) {
		for (size_t i = 0; i < size; ++i) {
			if (data[i].first == key) {
				data[i].second = value;
				return;
			}
		}

		if (size < MAX_SIZE) {
			data[size] = std::pair<Key, Value>(key, value);
			++size;
		}
	}

	bool remove(const Key& key) {
		for (size_t i = 0; i < size; ++i) {
			if (data[i].first == key) {
				--size;
				data[i] = data[size];
				return true;
			}
		}

		return false;
	}

	Value& operator[](const Key& key) {
		for (size_t i = 0; i < size; ++i) {
			if (data[i].first == key) {
				return data[i].seconddk;
			}
		}

		if (size < MAX_SIZE) {
			data[size] = std::pair<Key, Value>(key, Value());
			++size;
			return data[size - 1].second;
		}

		throw std::exception();
	}

	const Value& operator[](const Key& key) const{
		for (size_t i = 0; i < size; ++i) {
			if (data[i].first == key) {
				return data[i].second;
			}
		}

		throw std::exception();
	}

	bool contains(const Key& key) const {
		for (int i = 0; i < size_; ++i) {
			if (data_[i].first == key) {
				return true;
			}
		}
		return false;
	}

	void clear() { 
		size_ = 0;
	}

	size_t size() const { 
		return size_;
	}
};

#endif // !_DICTIONARY_H
