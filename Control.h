#ifndef CONTROL_H
#define CONTROL_H

#include "Hotel.h"
#include "ResManager.h"
#include "StayRecorder.h"
#include "GuestRecorder.h"
#include "UpgradeRecorder.h"
#include "Recorder.h"
#include "View.h"


class Control
{
	public:
		Control();
		~Control();
		void initHotel();
		void launch();
	
	private:
		View view;
		Hotel* hotel;
		ResManager* resMgr;
		StayRecorder* stayRecorder;
		GuestRecorder* guestRecorder;
		UpgradeRecorder* upgradeRecorder;
};

#endif
