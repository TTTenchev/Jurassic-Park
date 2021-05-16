#include<iostream>
#include"Dinosaur.h"
#include"Cells.h"
using namespace std;

int main() {
	//Dinosaur dino("Tisho", Male, Trias, "No Class", NoType, None);
	Dinosaur dino;
	cin >> dino;
	cout << "This is the Dino: " << endl;
	cout << dino << endl;
	Cage cage = Cage(3);
	cout << "This is the Cage: " << endl;
	cage.AddDino(&dino);
	cage.print();
	return 0;
}