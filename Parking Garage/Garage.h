#pragma once
#include "Lane.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Garage {
private:
	Lane *garage1, *garage2, *street;
	const int MAX_SIZE = 10;
public:
	Garage();
	~Garage();
	bool isFull(Lane lane);
	void arrive(Car car);
	void depart(Car car);
	bool isThere(Car car);
	Car moveCarOut(Car car, Lane *lane, Lane *street);
	void refillStack(Lane *lane, Lane *street);
	void timesCarMoved(Car car);
	void arriveOrDepart(Car car, char s);
	void initiate();
	void print();
};
Garage::Garage() {
	garage1 = new Lane[MAX_SIZE];
	garage2 = new Lane[MAX_SIZE];
	street = new Lane[MAX_SIZE];
}
Garage::~Garage() {
	delete[] garage1;
	delete[] garage2;
	delete[] street;
}
bool Garage::isFull(Lane car) {
	return car.getSize() == MAX_SIZE;
}
void Garage::arrive(Car car) {
	if (isThere(car)) {
		cout << "This is an imposter vehicle. We are contacting the police!" << endl;
		return;
	}
	if (!garage1->isFull()) {
		garage1->push(car);
		cout << car.getLicensePlate() << " was moved to Garage 1" << endl;
		return;
	}
	if (!garage2->isFull()) {
		garage2->push(car);
		cout << car.getLicensePlate() << " was moved to Garage 2" << endl;
		return;
	}
	cout << "There is no room for " << car.getLicensePlate() << ". Please return later." << endl;
}
void Garage::depart(Car car) {
	if (!isThere(car)) {
		cout << "This vehicle is not currently parked at this location." << endl;
		return;
	}
	if (garage1->contains(car)) {
		car = moveCarOut(car, garage1, street);
		refillStack(garage1, street);
	}
	else {
		car = moveCarOut(car, garage2, street);
		refillStack(garage2, street);
	}
	timesCarMoved(car);
}
bool Garage::isThere(Car car) {
	return garage1->contains(car) || garage2->contains(car);
}
Car Garage::moveCarOut(Car car, Lane *lane, Lane *street) {
	while (car.getLicensePlate() != lane->top().getLicensePlate()) {
		street->push(lane->top());
		lane->pop();
	}
	car = lane->top();
	lane->pop();
	street->increaseAllTimesMoved();

	return car;
}
void Garage::refillStack(Lane *lane, Lane *street) {
	while (!street->isEmpty()) {
		lane->push(street->top());
		street->pop();
	}
	lane->increaseAllTimesMoved();
}
void Garage::arriveOrDepart(Car car, char s) {
	if (s == 'A') {
		arrive(car);
	}
	else {
		depart(car);
	}
}
void Garage::timesCarMoved(Car car) {
	if (car.getTimesMoved() == 0) {
		cout << car.getLicensePlate() << " has been moved out of the garage."
			<< " It has never been moved." << endl;
	}
	else {
		cout << car.getLicensePlate() << " has been moved out of the garage."
			<< " It has been moved " << car.getTimesMoved() << " times." << endl;
	}
}
void Garage::initiate() {
	ifstream garageFile;
	garageFile.open("garage.txt");
	if (!garageFile.is_open()) {
		cout << "garage.txt is not found." << endl;
		exit(1);
	}
	char status, whitespace;
	string vehicle;
	while (!garageFile.eof()) {
		garageFile >> status;
		garageFile.get(whitespace);
		getline(garageFile, vehicle);
		Car car(vehicle);
		arriveOrDepart(car, status);
	}
	garageFile.close();
}
void Garage::print() {
	if (garage1->isEmpty()) {
		cout << "Garage1 is empty." << endl;
	}
	else {
		garage1->print();
	}
	if (garage2->isEmpty()) {
		cout << "Garage2 is empty." << endl;
	}
	else {
		garage2->print();
	}
	if (street->isEmpty()) {
		cout << "Street is empty." << endl;
	}
	else {
		street->print();
	}
}