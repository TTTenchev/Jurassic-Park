#pragma once
#include<iostream>
#include"String.cpp"
#include"Dinosaur.h"
#include"Vector.cpp"
using namespace std;


enum Climate {
	Water,
	Air,
	Ground,
	No_Climate
};

class Cage {
private:
	myVector<Dinosaur*> Dinos;
	int index = 0;
	int size = 0;
	Climate climate;
	int foodCapacity;
	int staffMembers;
public:
	Cage() {
		size = 0;
		index = 0;
		climate = No_Climate;
	}
	Cage(int size) {
		this->size = size;
		index = 0;
		climate = No_Climate;
	}
	~Cage() {
		//delete[] &Dinos;
		this->Dinos = nullptr;
	}
	bool AddDino(Dinosaur* other) {
		if (this->index < this->size) {
			if (this->index > 0) {
				for (int i = 0; i <= this->index; i++) {
					if (other->get_Era() != Dinos[i]->get_Era() ||
						other->get_Order() != Dinos[i]->get_Order()) {
						return false;
					}
				}
			}
			Dinos.pushBack(other);
			Dinos[++this->index] = NULL;
			return true;
		}
		return false;
	}
	void print () {
		for (size_t i = 0; i < this->size; i++) {
			//cout << this->Dinos[i] << endl;
		}
	}
};