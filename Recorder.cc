#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <vector>
#include "Recorder.h"

/*
Purpose of this program:
Base class of UpgradeRecorder, StayRecorder, GuestRecorder.

printRecords(): Loops through the recorder and prints out each record.
*/

Recorder::Recorder(string n){
	name = n;
}

void Recorder::printRecords(){
	cout << "Records for " << name << ":" << endl;
	for(int i = 0; i < collection.size(); i++){
		cout << collection[i] << endl;
	}
}
