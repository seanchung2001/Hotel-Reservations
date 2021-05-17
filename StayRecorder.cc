#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

#include "StayRecorder.h"

/*
Purpose of this program:
Stores informative strings for reservations made that are longer than 3 days in a vector of strings.

Complex or critical data members:

update(Reservation*): Checks if the reservation made was longer than 3 days. If so, it will store an informative string about the guest who made the reservation in the vector.
*/

StayRecorder::StayRecorder(string n)
	: Recorder(n)
{
}

void StayRecorder::update(Reservation* r){
	if(r->getNumDays() > 3){
		stringstream ss;
		ss << "Stay Recorder:   Guest   " << r->getGuest()->getName() << ",  " << r->getNumDays() << " nights";
		collection.push_back(ss.str());
	}
}
