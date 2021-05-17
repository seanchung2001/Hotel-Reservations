#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "ResManager.h"
#include "Hotel.h"

/*
Purpose of this program:
Manages all of the reservations that are made to the specific hotel.

Complex or critical data members:

addReservation(string, int, int, int, int, ReqRoomType): Uses the information in the parameter to create a reservation and store it in the collection of reservations. Also responsible for updating the Guets loyalty points and notifying the Recorders.

subscribe(Recorder*): Adds the given recorder to the collection of events stored as a vector.

print(): Prints all of the reservations made.

printRecords(): Prints all of the event recorders.

Notify(Reservation*): Notifies the event recorders to update.
*/

ResManager::ResManager(Hotel* h){
	hotel = h;
	numReservations = 0;
}

ResManager::~ResManager(){
	for(int i = 0; i < numReservations; i++){
		delete reservations[i];
	}
}

void ResManager::setHotel(Hotel* h){
	hotel = h;
}

void ResManager::addReservation(string n, int yr, int mth, int day, int stay, ReqRoomType req){
	if(stay <= 0 || stay >= 31){
		return;
	}
	Date* tmpDate = new Date(day, mth, yr);
	static RoomArray* rooms;
	hotel->getRooms(&rooms);
	Room* room = NULL;
	Guest* guest;
	bool guestFound = hotel->findGuest(n, &guest);
	if(guestFound == false){
		cout << "ERROR: Guest " << n << " does not exist" << endl;
		delete tmpDate;
		return;
	}
	bool flag;
	for(int i = 0; i < rooms->getSize(); i++){
		if(rooms->get(i)->getRoomType() == req){
			bool flag = true;
			for(int j = 0; j < numReservations; j++){
				if(n == reservations[j]->getGuest()->getName()){
					if(tmpDate->equals(reservations[j]->getDate())){
						cout << "ERROR: Registration request for " << n << ", ";
						tmpDate->print();
						cout << ": No room of matching type available" << endl;
						delete tmpDate;
						return;
					}
				}
				if(rooms->get(i) == reservations[j]->getRoom()){
					if(tmpDate->collides(reservations[j]->getDate(), stay) == true){
						flag = false;
					}
				}
			}
			if(flag == true){
				room = rooms->get(i);
				break;
			}
		}
	}
	if(room == NULL){
		cout << "ERROR: Registration request for " << n << ", ";
		tmpDate->print();
		cout << ": No room of matching type available" << endl;
		delete tmpDate;
		return;
	}
	Reservation* tmpRes = new Reservation(guest, tmpDate, room, stay);
	int addIndex = -1;
	if(numReservations == 0){
		this->reservations[numReservations] = tmpRes;
		numReservations++;
		int tmpPoints;
		room->computePoints(tmpPoints);
		tmpPoints = tmpPoints * stay;
		guest->addPts(tmpPoints);
		notify(tmpRes);
		return;
	}
	if(numReservations == MAX_ARR){
		delete tmpDate;
		return;
	}
	for(int i = 0; i < numReservations; i++){
		if(reservations[i]->lessThan(tmpRes) == false){
			addIndex = i;
			break;
		}
	}
	if(addIndex == -1){
		reservations[numReservations] = tmpRes;
		numReservations++;
		int tmpPoints;
		room->computePoints(tmpPoints);
		tmpPoints = tmpPoints * stay;
		guest->addPts(tmpPoints);
		notify(tmpRes);
		return;
	}
	for(int j = numReservations; j > addIndex; j--){
		this->reservations[j] = this->reservations[j-1];
	}
	this->reservations[addIndex] = tmpRes;
	numReservations++;
	
	
	int tmpPoints;
	room->computePoints(tmpPoints);
	tmpPoints = tmpPoints * stay;
	guest->addPts(tmpPoints);
	notify(tmpRes);
}

void ResManager::subscribe(Recorder* r){
	events.push_back(r);
}

void ResManager::print(){
	cout << "RESERVATIONS:" << endl;
	for(int i = 0; i < numReservations; i++){
		reservations[i]->print();
	}
}

void ResManager::printRecords(){
	cout << "EVENT RECORDS:" << endl << endl;
	for(int i = 0; i < events.size(); i++){
		events[i]->printRecords();
		cout << endl;
	}
}

void ResManager::notify(Reservation* r){
	for(int i = 0; i < events.size(); i++){
		events[i]->update(r);
	}
}
