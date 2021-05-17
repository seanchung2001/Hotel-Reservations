#include "Control.h"

/*
Purpose of this program:

The purpose of this program was to continue practicing working with inheritance and composition. Also, this assignment has us working with polymorphism and linked lists. Finally, we were able to continue with practicing our UML class diagrams.

Usage: 

Create a simulation of a hotel, and creating reservations for the hotel. The hotel stores Guests and Rooms which the Reservation manager uses to create necessary reservations for the hotel. The guests store loyalty points which are incremented by a certain amount after a reservation is made. Our program can: (1) printReservations(): Prints out all of the reservations that were made for with the given reservation manager in ascending order based on the arrival date of the reservation. (2) printRooms(): Print out all of the rooms in the hotel in a specified format, not in any given order. (3) printGuests(): Print out all of the Guests registered for the hotel in a specified format, not in any given order. (4) printRecords(): Prints out all of the event recorders in a specified format, not in any given order.

Author(s): Sunyeop (Sean) Chung

All revisions:
*/

int main(){
	Control* control = new Control();
	control->launch();
	delete control;
	return 0;
}
