#ifndef GUESTRECORDER_H
#define GUESTRECORDER_H

#include <string>
using namespace std;

#include "Recorder.h"
#include "Reservation.h"

class GuestRecorder: public Recorder
{
  public:
  	GuestRecorder(string="");
  	virtual void update(Reservation*);
  	
  private:
  	
};

#endif
