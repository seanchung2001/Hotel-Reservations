#ifndef STAYRECORDER_H
#define STAYRECORDER_H

#include <string>
using namespace std;

#include "Recorder.h"
#include "Reservation.h"

class StayRecorder: public Recorder
{
  public:
  	StayRecorder(string="");
  	virtual void update(Reservation*);
  	
  private:
  	
};

#endif
