#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Room.h"

/*
Purpose of this program:
Acts as a room for a hotel. Data member for the Hotel class. Stores the room number, the type of room, and the cost of the room daily.

Complex or critical data members:

print(): Prints all the information for the room in a specified format.

computePoints(int&): Computes the loyalty points to be accrued by the Guest and returns the number through address.
*/

Room::Room(ReqRoomType r, int n, float d){
	roomType = r;
	roomNum = n;
	dailyCost = d;
}

ReqRoomType Room::getRoomType(){
	return roomType;
}

int Room::getRoomNum(){
	return roomNum;
}

float Room::getDailyCost(){
	return dailyCost;
}

void Room::print(){
	cout << "-- " << roomNum;
	if(roomType == C_REG){
		cout << " Regular room: $" << dailyCost << ".00 per night" << endl;
	}
	else if(roomType == C_PREM){
		cout << " Premium room: $" << dailyCost << ".00 per night" << endl;
	}
	else if(roomType == C_SUITE){
		cout << " Suite   room: $" << dailyCost << ".00 per night" << endl;
	}
}

void Room::computePoints(int& pts){
	if(roomType == C_REG){
		pts = dailyCost * 0.10;
	}
	else if(roomType == C_PREM){
		pts = dailyCost * 0.15;
	}
	else if(roomType == C_SUITE){
		pts = dailyCost * 0.20;
	}
}
