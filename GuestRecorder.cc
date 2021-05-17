#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

#include "GuestRecorder.h"

/*
Purpose of this program:

Stores informative strings about Guests who made a reservation for a premium or suite room in a vector of strings.

Complex or critical members:

update(Reservation*): Checks if the reservation made was to a premium or suite style room. If so, it will store an informative string about the Guest who made the reservation in a vector.
*/

GuestRecorder::GuestRecorder(string n)
	: Recorder(n)
{
}

void GuestRecorder::update(Reservation* r){
	if(r->getGuest()->getIsPremium() == false){
		if(r->getRoom()->getRoomType() == C_PREM || r->getRoom()->getRoomType() == C_SUITE){
			stringstream ss;
			ss << "Guest Recorder:  premium guest offer for " << r->getGuest()->getName();
			collection.push_back(ss.str());
		}
	}	
}
