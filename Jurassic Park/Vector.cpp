#pragma once
#include <iostream>
using namespace std;

template <typename T>
class myVector {
private:
	T* arr;
	int size;
	int capacity;
	void copy(const myVector<T>& other) {
		if (this != &other)
		{
			size = other.size;
			capacity = other.capacity;
			arr = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
	}
	void resize() {
		capacity *= 2;
		T* buffer = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr;
		arr = new T[capacity];
		arr = buffer;
	}
	void destroy() {
		delete[] arr;
	}
public:
	myVector() {
		arr = nullptr;
		size = 0;
		capacity = 0;
	}
	myVector(const myVector<T>& other);
	myVector(const T*);
	int get_size()const {
		return size;
	}
	int get_capacity()const {
		return capacity;
	}
	myVector<T>& operator=(const myVector<T>& other);
	T& operator[] (const int index) const;
	//friend ostream& operator<<(ostream& out, myVector& other);
	//friend istream& operator>>(istream& in, myVector& other);
	void pushBack(const T& index);
	~myVector() {
		delete[] arr;
	}
	void print();
};
template<typename T>
myVector<T>::myVector(const myVector<T>& other) {
	copy(other);
}
template<typename T>
myVector<T>::myVector(const T* arr_) {
	size_t _size = 0;
	while (arr_[_size] != NULL) {
		_size += 1;
	}
	int _capacity = 8;
	while (_capacity < sizeof(arr_))
	{
		_capacity *= 2;
	}
	this->size = _size;
	cout << "Size of Vector is: " << this->size << endl;
	this->capacity = _capacity;
	this->arr = new T[_capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = arr_[i];
	}
}
template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& other) {
	if (this != &other)
	{
		if (this != nullptr) {
			destroy();
		}
		copy(other);
	}
	return *this;
}
template <typename T>
T& myVector<T>:: operator[] (const int index)const {
	if (index > size)
	{
		exit(1);
	}
	return arr[index];
}
template<typename T>
void myVector<T>::pushBack(const T& index) {
	if (size + 1 >= capacity)
	{
		resize();
	}
	arr[size] = index;
	size += 1;
}
template<typename T>
void myVector<T>::print() {
	for (int i = 0; i < this->size; i++) {
		cout << this->arr[i] << endl;
	}
}
//template<typename T>
/*ostream& operator<<(ostream& out, myVector<T>& other) {
	for (size_t i = 0; i < this->size; i++) {
		cout << other.arr[i] << " ";
	}
	cout << endl;
	cout << size << endl;
	return out;
}*/
/*template<typename T>
istream& operator>>(istream& in, myVector<T>& other) {
	T arr[20];
	cin >> arr;
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		this->arr[i] = arr[i];
	}
	this->size = sizeof(arr) / sizeof(*arr);
	this->capacity = 8;
	while (capacity < size) {
		this->capacity *= 2;
	}
	return in;
}*/