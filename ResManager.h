#ifndef RESMANAGER_H
#define RESMANAGER_H

#include <string>
#include <vector>
using namespace std;

#include "defs.h"
#include "RoomArray.h"
#include "Recorder.h"
#include "Reservation.h"

class Hotel;

class ResManager
{
  public:
  	ResManager(Hotel*);
  	~ResManager();
  	void setHotel(Hotel*);
  	void subscribe(Recorder*);
  	void print();
  	void printRecords();
  	void addReservation(string, int, int, int, int, ReqRoomType);
  	
 
  private:
  	Hotel* hotel;
  	Reservation* reservations[100];
  	int numReservations;
  	vector<Recorder*> events;
  	void notify(Reservation*);
  	
};

#endif
