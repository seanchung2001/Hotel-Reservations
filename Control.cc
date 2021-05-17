#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

/*
Purpose of this program:

Controls the entire program. Includes data members that are appropriate for calling functions and calculating necessary reservations in a hotel, Guests in a hotel, etc. This program will call the functions from other src files to do so.

Complex or Critical Data members:

initHotel(): Adds Guests and Rooms to the hotel, and adds reservations to the reservation manager. This is required to set up our program for testing.
launch(): Controls the program. the main function will call the launch() function to set up the program by calling the initHotel() function, then calling the necessary functions from the hotel and reservation manager data members.
*/

Control::Control(){
	resMgr = new ResManager(hotel);
	hotel = new Hotel("Sean's Hotel", resMgr);
	resMgr->setHotel(hotel);
	stayRecorder = new StayRecorder("Stay Recorder");
	guestRecorder = new GuestRecorder("Guest Recorder");
	upgradeRecorder = new UpgradeRecorder("Upgrade Recorder");
	resMgr->subscribe(stayRecorder);
	resMgr->subscribe(guestRecorder);
	resMgr->subscribe(upgradeRecorder);
}

Control::~Control(){
	delete resMgr;
	delete hotel;
	delete stayRecorder;
	delete guestRecorder;
	delete upgradeRecorder;
}

void Control::initHotel()
{
  hotel->addGuest(new Guest("Juliet", true));
  hotel->addGuest(new Guest("Ben", true));
  hotel->addGuest(new Guest("Goodwin"));
  hotel->addGuest(new Guest("Harper", true));
  hotel->addGuest(new Guest("Ethan"));
  hotel->addGuest(new Guest("Horace"));
  hotel->addGuest(new Guest("Aimee"));

  hotel->addRoom(new Room(C_SUITE, 501, 1500));
  hotel->addRoom(new Room(C_PREM, 410, 700));
  hotel->addRoom(new Room(C_PREM, 420, 700));
  hotel->addRoom(new Room(C_REG, 322, 300));
  hotel->addRoom(new Room(C_REG, 324, 300));
  hotel->addRoom(new Room(C_REG, 326, 300));
  hotel->addRoom(new Room(C_REG, 212, 200));
  hotel->addRoom(new Room(C_REG, 214, 200));
  hotel->addRoom(new Room(C_REG, 216, 200));
  hotel->addRoom(new Room(C_REG, 218, 200));
  
  
  resMgr->addReservation("Ben",     2021, 5, 11,  4, C_PREM);
  resMgr->addReservation("Juliet",  2021, 5, 10,  3, C_PREM);
  resMgr->addReservation("Horace",  2021, 5, 28, 10, C_PREM);
  resMgr->addReservation("Aimee",   2021, 5, 28,  8, C_PREM);
  resMgr->addReservation("Sophie",  2021, 5, 28,  8, C_PREM);
  resMgr->addReservation("Harper",  2021, 5, 12,  1, C_PREM);
  resMgr->addReservation("Harper",  2021, 5, 12,  1, C_REG);
  resMgr->addReservation("Ethan",   2021, 5,  8,  7, C_REG);
  resMgr->addReservation("Ethan",   2021, 5, 28, 10, C_REG);
  resMgr->addReservation("Timmy",   2021, 5, 28,  8, C_REG);
  resMgr->addReservation("Horace",  2021, 5, 25,  2, C_REG);
  resMgr->addReservation("Goodwin", 2021, 5, 25, 12, C_REG);
  resMgr->addReservation("Ben",     2021, 5, 27,  5, C_REG);
  resMgr->addReservation("Harper",  2021, 5, 29,  2, C_SUITE);
  resMgr->addReservation("Juliet",  2021, 5, 30,  1, C_SUITE);

}

void Control::launch(){
	initHotel();
	int choice;
	view.showMenu(choice);
	while(choice != 0){
		if(choice == 1){
			resMgr->print();
			view.showMenu(choice);
		}
		else if(choice == 2){
			hotel->printRooms();
			view.showMenu(choice);
		}
		else if(choice == 3){
			hotel->printGuests();
			view.showMenu(choice);
		}
		else if(choice == 4){
			resMgr->printRecords();
			view.showMenu(choice);
		}
		else if(choice == 0){
			return;
		}
	}
}
