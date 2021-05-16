#pragma once
#include"String.cpp"
using namespace std;

enum era {
	Trias,
	Creda,
	Yura,
	Non_Existant
};
enum food {
	Meat,
	Grass,
	Fish,
	None
};
enum gender {
	Male,
	Female,
	Other,
	Non_Binary
};
enum order {
	Vegan,
	Predator,
	Flying,
	Underwater,
	No_Order
};
enum type {
	//predators
	Allosaurus,
	Velociraptor,
	Aucasaurus,
	Carnotaurus,
	Coelurus,
	Deinonychus,
	//plant-eaters
	Edmontonia,
	Erketu,
	Eolambia,
	Dacentrurus,
	Chubutisaurus,
	//animals and plant eaters
	Deinocheirus,
	Khaan,
	//default
	NoType
};


class Dinosaur {
private:
	myString Name;
	gender Gender;
	era Era;
	order Order;
	type Type;
	food Food;
	//bool isHarmful;
public:
	Dinosaur();
	Dinosaur(myString, gender, era, myString, type, food);
	friend ostream& operator<<(ostream& out, Dinosaur& other);
	friend istream& operator>>(istream& in, Dinosaur& other);
	Dinosaur& operator=(Dinosaur& other);
	void set_Name(const myString& other) {
		this->Name = other;
	}
	void set_Gender(const gender& Gender) {
		this->Gender = Gender;
	}
	void set_Era(const era& Era) {
		this->Era = Era;
	}
	void set_Class(const order& other) {
		this->Order = other;
	}
	void set_Type(const type& Type) {
		this->Type = Type;
	}
	void set_Food(const food& Food) {
		this->Food = Food;
	}
	myString& get_Name() {
		return this->Name;
	}
	gender get_Gender() {
		return this->Gender;
	}
	era get_Era() {
		return this->Era;
	}
	order& get_Order() {
		return this->Order;
	}
	type get_Type() {
		return this->Type;
	}
	food get_Food() {
		return this->Food;
	}
};