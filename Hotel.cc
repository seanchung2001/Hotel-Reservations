#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Hotel.h"

/*
Purpose of this program:
Acts as a hotel. Manages the Guests in the hotel, as well as the rooms.

Complex or critical data members:

addGuest(Guest*): Adds the specified Guest to the collection of guests for this hotel.

addRoom(Room*): Adds the specified Room to the collection of rooms for this guest.

findGuest(string, Guest**): Finds a guest with the specified name, and returns the guest by pointer.
*/

Hotel::Hotel(string n, ResManager* r){
	name = n;
	manager = r;
	rooms = new RoomArray();
	numGuests = 0;
}

Hotel::~Hotel(){
	for(int i = 0; i < numGuests; i++){
		delete guests[i];
	}
	delete rooms;
}

void Hotel::getRooms(RoomArray** r){
	(*r) = rooms;
}

void Hotel::addGuest(Guest* g){
	if(numGuests == MAX_ARR){
		return;
	}
	guests[numGuests] = g;
	numGuests++;
}

void Hotel::addRoom(Room* r){
	rooms->add(r);
}

void Hotel::printGuests(){
	cout << "GUESTS:" << endl << endl;
	for(int i = 0; i < numGuests; i++){
		guests[i]->print();
	}
}

void Hotel::printRooms(){
	cout << "ROOMS:" << endl << endl;
	rooms->print();
}

bool Hotel::findGuest(string n, Guest** g){
	for(int i = 0; i < numGuests; i++){
		if(guests[i]->getName() == n){
			*g = guests[i];
			return true;
		}
	}
	return false;
}
