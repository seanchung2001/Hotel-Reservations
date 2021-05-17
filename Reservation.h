#ifndef RESERVATION_H
#define RESERVATION_H


#include "Guest.h"
#include "Room.h"
#include "Date.h"

class Reservation
{
  public:
  	Reservation(Guest*, Date*, Room*, int=0);
  	~Reservation();
  	Guest* getGuest();
  	Room* getRoom();
  	float getCharge();
  	Date* getDate();
  	int getNumDays();
  	bool lessThan(Reservation*);
  	void print();
  	
  private:
  	Guest* guest;
  	Date* arrivalDate;
  	int numDays;
  	Room* room;
  	float charge;
};

#endif
