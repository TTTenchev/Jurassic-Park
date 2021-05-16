#pragma once
#include"Dinosaur.h"
using namespace std;

myString& enumToCharGender(gender Gender, myString& genderType) {
	if (Gender == gender::Male) {
		genderType = "Male";
		return genderType;
	}
	else if (Gender == gender::Female) {
		genderType = "Female";
		return genderType;
	}
	else if (Gender == gender::Non_Binary) {
		genderType = "Non Binary";
		return genderType;
	}
	else {
		genderType = "Other";
		return genderType;
	}
}
gender CharToEnumGender(myString& genderType) {
	if (genderType == "Male") {
		return Male;
	}
	else if (genderType == "Female") {
		return Female;
	}
	else if (genderType == "Non Binary") {
		return Non_Binary;
	}
	else {
		return Other;
	}
}
myString& enumToCharEra(era Era, myString& EraType) {
	if (Era == Trias) {
		return (EraType = "Trias");
	}
	else if (Era == Creda) {
		return EraType = "Creda";
	}
	else if (Era == Yura) {
		return EraType = "Yura";
	}
	else {
		return EraType = "Non Existant";
	}
}
era CharToEnumEra(myString& EraType){
	if (EraType == "Trias") {
		return Trias;
	}
	else if (EraType == "Creda") {
		return Creda;
	}
	else if (EraType == "Yura") {
		return Yura;
	}
	else {
		return Non_Existant;
	}
}
myString& enumToCharType(type Type, myString& type) {
	if (Type == Allosaurus) {
		return type = "Allosaurus";
	}
	else if (Type == Velociraptor) {
		return type = "Velociraptor";
	}
	else if (Type == Aucasaurus) {
		return type = "Aucasaurus";
	}
	else if (Type == Carnotaurus) {
		return type = "Carnotaurus";
	}
	else if (Type == Coelurus) {
		return type = "Coelurus";
	}
	else if (Type == Deinonychus) {
		return type = "Deinonychus";
	}
	else if (Type == Edmontonia) {
		return type = "Edmontonia";
	}
	else if (Type == Erketu) {
		return type = "Erketu";
	}
	else if (Type == Eolambia) {
		return type = "Eolambia";
	}
	else if (Type == Dacentrurus) {
		return type = "Dacentrurus";
	}
	else if (Type == Chubutisaurus) {
		return type = "Chubutisaurus";
	}
	else if (Type == Deinocheirus) {
		return type = "Deinocheirus";
	}
	else if (Type == Khaan) {
		return type = "Khaan";
	}
	else {
		return type = "NoType";
	}
}
order CharToEnumOrder(myString& OrderType) {
	if (OrderType == "Vegan") {
		return Vegan;
	}
	else if (OrderType == "Predator") {
		return Predator;
	}
	else if (OrderType == "Flying") {
		return Flying;
	}
	else if (OrderType == "Underwater") {
		return Underwater;
	}
	else {
		return No_Order;
	}
}
myString& enumToCharOrder(order Order, myString& OrderType) {
	if (Order == Vegan) {
		return OrderType = "Vegan";
	}
	else if (Order == Predator) {
		return OrderType = "Predator";
	}
	else if (Order == Flying) {
		return OrderType = "Flying";
	}
	else {
		return OrderType = "Underwater";
	}
}
type CharToEnumType(myString& Type) {
	if (Type == "Allosaurus") {
		return Allosaurus;
	}
	else if (Type == "Velociraptor") {
		return Velociraptor;
	}
	else if (Type == "Aucasaurus") {
		return Aucasaurus;
	}
	else if (Type == "Carnotaurus") {
		return Carnotaurus;
	}
	else if (Type == "Coelurus") {
		return Coelurus;
	}
	else if (Type == "Deinonychus") {
		return Deinonychus;
	}
	else if (Type == "Edmontonia") {
		return Edmontonia;
	}
	else if (Type == "Erketu") {
		return Erketu;
	}
	else if (Type == "Eolambia") {
		return Eolambia;
	}
	else if (Type == "Dacentrurus") {
		return Dacentrurus;
	}
	else if (Type == "Chubutisaurus") {
		return Chubutisaurus;
	}
	else if (Type == "Deinocheirus") {
		return Deinocheirus;
	}
	else if (Type == "Khaan") {
		return Khaan;
	}
	else {
		return NoType;
	}
}
myString& enumToCharFood(food Food, myString& FoodType) {
	if (Food == Meat) {
		return FoodType = "Meat";
	}
	else if (Food == Fish) {
		return FoodType = "Fish";
	}
	else if (Food == Grass) {
		return FoodType = "Grass";
	}
	else {
		return FoodType = "None";
	}
}
food CharToEnumFood(myString& Food) {
	if (Food == "Meat") {
		return Meat;
	}
	else if (Food == "Fish") {
		return Fish;
	}
	else if (Food == "Grass") {
		return Grass;
	}
	else {
		return None;
	}
}
/*bool isItHarmful(type type) {
	if(type == )
}*/

Dinosaur::Dinosaur() {
	this->Name = "No Name";
	this->Gender = Non_Binary;
	this->Era = Non_Existant;
	this->Order = No_Order;
	this->Type = NoType;
	this->Food = None;
	//this->isHarmful = false;
}
Dinosaur::Dinosaur(myString name, gender gender, era era, myString Class, type type, food food) {
	this->Name = name;
	this->Gender = gender;
	this->Era = era;
	this->Order = Order;
	this->Type = type;
	this->Food = food;
	//this->isHarmful = isItHarmful(type);
}
Dinosaur& Dinosaur::operator=(Dinosaur& other) {
	if (this != &other) {
		Name = other.Name;
		Gender = other.Gender;
		Era = other.Era;
		Order = other.Order;
		Type = other.Type;
		Food = other.Food;
	}
	return *this;
}
istream& operator>>(istream& in, Dinosaur& other) {
	myString buffer;
	cout << "Enter name of the dinosaur: " << endl;
	in >> buffer;
	other.set_Name(buffer);
	cout << "Enter Gender of the dinosaur: " << endl;
	in >> buffer;
	other.set_Gender(CharToEnumGender(buffer));
	cout << "Enter Era for the dinosaur: Choices are (Trias, Yura, Creda)" << endl;
	in >> buffer;
	other.set_Era(CharToEnumEra(buffer));
	cout << "Enter Order for the dinosaur: Choices are (Predator, Vegan, Flying, Ground)" << endl;
	in >> buffer;
	other.set_Class(CharToEnumOrder(buffer));
	cout << "Enter Type for the dinosaur: " << endl;
	in >> buffer;
	other.set_Type(CharToEnumType(buffer));
	cout << "Enter Food for the dinosaur: Choices are (Meat, Fish, Grass) " << endl;
	in >> buffer;
	other.set_Food(CharToEnumFood(buffer));
	return in;
}
ostream& operator<<(ostream& out, Dinosaur& other) {
	cout << other.Name << endl;
	myString Output;
	Output = enumToCharGender(other.Gender, Output);
	cout << Output << endl;
	Output = enumToCharEra(other.Era, Output);
	cout << Output << endl;
	Output = enumToCharOrder(other.Order, Output);
	cout << Output << endl;
	Output = enumToCharType(other.Type, Output);
	cout << Output << endl;
	Output = enumToCharFood(other.Food, Output);
	cout << Output << endl;
	return out;
}