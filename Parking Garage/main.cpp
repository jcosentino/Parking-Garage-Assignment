/*
This is an assignment from CSC 326 Data Structures.
The project involves an array-implementation of the Stack.
Project description is copy and pasted below.
Project includes a .txt file that denotes what 
vehicles arrive and when.
*/
#include "Lane.h"
#include "Garage.h"
#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Garage g;
	g.initiate();

	system("pause");
	return 0;
}
/*
The CSC326 Parking Garage contains 2 lanes, each capable of holding up to 10 cars.
There is only a single entrance/exit to the garage at one end of the lanes.
If a customer arrives to pick up a car which is not nearest the exit, all
cars blocking the cars' path are moved into the other lane. If more cars still
must be moved out of the way, they go into the street. When the customer's car
is driven out, all cars in the street must be put back into the garage.
Write a C++ program that reads input from either a file (that you create). Each
line in the file contain two fields separated by a blank: a code (A = an arriving
car, or D= a car wishes to depart) and a license plate number (this could be a string).
Cars are assumed to arrive and depart in the order specified by the input. The program
should print a message whenever a car arrives or departs. When a car arrives, the
message should specify whether or not there is room in the garage for the car. If there
is no room, the car leaves without entering. When a car departs, the message should
include the number of times the car had to be moved out of the way so that other cars
could depart. Each move from one lane to the other counts as 1; each move to the street
counts as 1; each move from the street to a lane counts as 1. Don't forget to check for
screwy things - e.g. someone wanting a car that's not in the garage, trying to park a car
but both lanes are full, trying to park a car when only one lane is full, etc.
Your program should define objects from a 'lane' class to represent the 2 lanes and the
street. The lane class will contain three stack objects one for each lane and the street.
Represent the cars in each lane using a car class. The car class can contain variables that
hold its license plate, and the number of times it’s moved.  You'll need methods for
manipulating the cars in the lanes, e.g. search for a car in a lane, move a car from a
lane to somewhere, and perhaps higher-level methods like arrive and depart and methods to
handle your output. This is NOT a complete list of methods needed, so feel free to experiment
and expand the class definitions as much as you like.
*/