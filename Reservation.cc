#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Reservation.h"

/*
Purpose of this program:
Reservation class which will be used by the ResManager class. Stores the guest, arrival date, room number, stay, and the total charge to act as a reservtion made.

Complex or critical data members:

lessThan(Reservation*): Checks if the specified Reservation's date in the parameter is less than the calling Reservation's date.

print(): Prints the information for the reservation in a specified format.
*/

Reservation::Reservation(Guest* g, Date* d, Room* r, int n){
	guest = g;
	arrivalDate = d;
	room = r;
	numDays = n;
	charge = room->getDailyCost() * numDays;
}

Reservation::~Reservation(){
	delete arrivalDate;
}

Guest* Reservation::getGuest(){
	return guest;
}

Room* Reservation::getRoom(){
	return room;
}

int Reservation::getNumDays(){
	return numDays;
}

Date* Reservation::getDate(){
	return arrivalDate;
}

float Reservation::getCharge(){
	return charge;
}

bool Reservation::lessThan(Reservation* r){
	if(arrivalDate->lessThan(r->arrivalDate) == true){
		return true;
	}
	else{
		return false;
	}
}

void Reservation::print(){
	cout << "-- Guest:  " << guest->getName() << "; Room: " << room->getRoomNum() << "; arrival: ";
	arrivalDate->print();
	cout << "; stay: " << numDays << "; total: $" << charge << ".00" << endl;
}
