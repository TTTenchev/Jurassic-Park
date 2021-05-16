#pragma once
#include<iostream>
#include<cstring>
using namespace std;


class myString {
private:
	char* str;
	size_t size;
	void copy(const myString& other) {
		this->str = new char[other.size + 1];
		strcpy_s(this->str, other.size + 1, other.str);
		this->size = other.size;
	}
	void destroy() {
		delete[] str;
		str = nullptr;
		size = 0;
	}
public:
	myString() {
		str = nullptr;
		size = 0;
	}
	myString(const char* str) {
		this->str = new char[strlen(str) + 1];
		strcpy_s(this->str, strlen(str) + 1, str);
		this->size = strlen(str) + 1;
	}
	myString(size_t size) {
		this->str = new char[size];
		this->size = size;
	}
	myString(const myString& other) {
		copy(other);
	}

	~myString() {
		destroy();
	}




	bool isEmpty(const myString& other) {
		return (size == 0);
	}

	size_t get_size() {
		return this->size;
	}
	char* get_str() {
		return str;
	}
	char operator[](const size_t index) {
		if (index >= size) {
			exit(-1);
		}
		return str[index];
	}
	myString concat(const myString& other)
	{
		return operator+(other);
	}
	myString operator+(const myString& other) {
		myString buffer;
		buffer.str = new char[this->size + other.size];
		buffer.size = this->size + other.size - 1;
		for (size_t i = 0; i < this->size; i++) {
			buffer.str[i] = this->str[i];
		}
		for (size_t i = 0; i < other.size; i++) {
			buffer.str[this->size + i - 1] = other.str[i];
		}
		return buffer;
	}
	myString& operator+=(const myString& other) {
		*this = *this + other;
		return *this;
	}
	myString& operator=(const myString& other) {
		if (this != &other) {
			if (this != nullptr) {
				destroy();
			}
			copy(other);
		}
		return *this;
	}
	bool operator==(const myString& other) {
		bool same = true;
		size_t i = 0;
		while (size != i) {
			if (str[i] == other.str[i]) {
				i++;
			}
			else {
				return false;
			}
		}
		return true;
	}
	bool operator !=(const myString& other) {
		return !(*this == other);
	}
	friend ostream& operator<<(ostream& out, myString& other) {
		for (size_t i = 0; i < other.get_size(); i++) {
			out << other.str[i];
		}
		return out;
	}
	friend istream& operator>>(istream& in, myString& other) {
		char buffer[100];
		cin >> buffer;
		other.str = new char[strlen(buffer) + 1];
		strcpy_s(other.str, strlen(buffer) + 1, buffer);
		other.size = strlen(buffer);
		return in;
	}
	void reverse() {
		for (size_t i = 0; i < this->size / 2; i++) {
			swap(this->str[i], this->str[this->size - i - 1]);
		}
	}
};