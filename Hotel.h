#ifndef HOTEL_H
#define HOTEL_H

#include <string>
using namespace std;

#include "ResManager.h"
#include "Guest.h"
#include "RoomArray.h"
#include "Room.h"

class Hotel
{
  public:
  	Hotel(string="", ResManager* = NULL);
  	~Hotel();
  	void getRooms(RoomArray**);
  	void addGuest(Guest*);
  	void addRoom(Room*);
  	void printGuests();
  	void printRooms();
  	bool findGuest(string n, Guest** g);
 
  private:
  	string name;
  	Guest* guests[MAX_ARR];
  	int numGuests;
  	RoomArray* rooms;
  	ResManager* manager;
};

#endif
