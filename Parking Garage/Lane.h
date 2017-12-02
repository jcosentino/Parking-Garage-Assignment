#pragma once
#include "Car.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Lane {
private:
	int size;
	Car *stack;
	const int MAX_SIZE = 10;
public:
	Lane();
	~Lane();
	int getSize();
	bool isEmpty();
	bool isFull();
	Car top();
	void push(Car item);
	void pop();
	bool contains(Car item);
	void increaseAllTimesMoved();
	void print();
};

Lane::Lane() {
	size = 0;
	stack = new Car[MAX_SIZE];
}
Lane::~Lane() {
	delete[] stack;
}
int Lane::getSize() {
	return size;
}
bool Lane::isEmpty() {
	return size == 0;
}
bool Lane::isFull() {
	return size == MAX_SIZE;
}
Car Lane::top() {
	if (isEmpty()) {
		cout << "Stack is empty." << endl;
		return "";
	}
	return stack[size - 1];
}
void Lane::push(Car item) {
	if (isFull()) {
		cout << "Stack is full." << endl;
		return;
	}
	stack[size] = item;
	size++;
}
void Lane::pop() {
	if (isEmpty()) {
		cout << "Stack is empty." << endl;
		return;
	}
	size--;
}
bool Lane::contains(Car car) {
	for (int i = 0; i < getSize(); i++) {
		if (car.getLicensePlate() == stack[i].getLicensePlate()) {
			return true;
		}
	}
	return false;
}
void Lane::increaseAllTimesMoved() {
	for (int i = 0; i < size; i++) {
		stack[i].incTimesMoved();
	}
}
void Lane::print() {
	for (int i = size - 1; i >= 0; i--) {
		cout << "License plate: " << stack[i].getLicensePlate() << endl;
		cout << "Times moved: " << stack[i].getTimesMoved() << endl;
	}
}