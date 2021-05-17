#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Guest.h"

/*
Purpose of this program:

The Guest class will act as data members for the hotel class as well as the reservation class. Acting as a guest for the hotel class and the guest who made the reservation for the reservation class.

Complex or critical members:

addPts(int): Adds the given amount of loyalty points to the Guest's current number of loyalty points.

print(): Prints the guest's information in a specified format.
*/

Guest::Guest(string n, bool p){
	name = n;
	isPremium = p;
	loyalPoints = 0;
}

string Guest::getName(){
	return name;
}

bool Guest::getIsPremium(){
	return isPremium;
}

void Guest::addPts(int p){
	loyalPoints += p;
}

void Guest::print(){
	cout << "-- " << name << "  ";
	if(isPremium == true){
		cout << "Premium guest:   " << loyalPoints << "pts" << endl;
	}
	else{
		cout << "Regular guest:   " << loyalPoints << "pts" << endl;
	}
}
