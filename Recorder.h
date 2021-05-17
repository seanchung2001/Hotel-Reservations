#ifndef RECORDER_H
#define RECORDER_H

#include <vector>

#include "Reservation.h"

class Recorder
{
  public:
  	Recorder(string="");
  	void printRecords();
  	virtual void update(Reservation*) = 0;
  protected:
  	string name;
  	vector<string> collection;
};

#endif
