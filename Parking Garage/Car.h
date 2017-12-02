#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
	string licensePlate;
	int timesMoved;
public:
	Car();
	Car(string licensePlate);
	string getLicensePlate();
	int getTimesMoved();
	void incTimesMoved();
	void print();
};
Car::Car() {
	licensePlate = "";
	timesMoved = 0;
}
Car::Car(string licensePlate) {
	this->licensePlate = licensePlate;
	timesMoved = 0;
}
string Car::getLicensePlate() {
	return licensePlate;
}
int Car::getTimesMoved() {
	return timesMoved;
}
void Car::incTimesMoved() {
	timesMoved++;
}
void Car::print() {
	cout << "License plate: " << licensePlate << endl;
	if (timesMoved == 0) {
		cout << "This car has never been moved." << endl;
	}
	else {
		cout << "Number of times moved: " << timesMoved << endl;
	}
}