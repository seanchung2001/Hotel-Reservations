#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

#include "UpgradeRecorder.h"

/*
Purpose of this program:
Stores informative strings for reservations that cost over $1500 in a vector of strings.

Complex or critical data members:

update(Reservation*): Checks if the reservation made costs over $1500. If so, it will store an informative string about the guest who made the reservation and store it in the vector.
*/

UpgradeRecorder::UpgradeRecorder(string n)
	: Recorder(n)
{
}

void UpgradeRecorder::update(Reservation* r){
	if(r->getGuest()->getIsPremium() == false){	
		if(r->getCharge() > 1500.0){
			stringstream ss;
			ss << "Upgrade Recorder:   Guest   " << r->getGuest()->getName() << ",  $" << r->getCharge();
			collection.push_back(ss.str());
		}
	}	
}
