#ifndef UPGRADERECORDER_H
#define UPGRADERECORDER_H

#include <string>
using namespace std;

#include "Recorder.h"
#include "Reservation.h"

class UpgradeRecorder: public Recorder
{
  public:
  	UpgradeRecorder(string="");
  	virtual void update(Reservation*);
  	
  private:
  	
};

#endif
