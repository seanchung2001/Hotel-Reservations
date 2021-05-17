#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

#include "defs.h"

class Room
{
  public:
  	Room(ReqRoomType, int=0, float=0.0);
  	ReqRoomType getRoomType();
  	int getRoomNum();
  	float getDailyCost();
  	void print();
  	void computePoints(int& pts);
  private:
  	ReqRoomType roomType;
  	int roomNum;
  	float dailyCost;
};

#endif
