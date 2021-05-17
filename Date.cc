#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

/*
Purpose of this program:

Date class will act as a data member for other programs to store the date of the reservation.

Complex or critical members:

add(int): Adds the specified amount of days to th current date.

lessThan(Date*): Checks if the date specified in the parameter is less than the calling date.

equals(Date*): Checks if the date specified in the parameter is equal to the calling date.

collides(Date*): Checks if the date specified in the parameter collides with the calling date.
*/

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date()
{
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

void Date::add(int duration){
	if(day + duration > lastDayInMonth() && month == 12){
		day = (day + duration) - lastDayInMonth();
		month = 1;
		year += 1;
	}
	else if(day + duration > lastDayInMonth()){
		day = (day + duration) - lastDayInMonth();
		month += 1;
	}
	else{
		day += duration;
	}
}

void Date::print()
{
  cout<<setfill('0')<<setw(4)<<year<<"-"
      <<setfill('0')<<setw(2)<<month<<"-"
      <<setfill('0')<<setw(2)<<day;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

bool Date::lessThan(Date* d)
{
	//Checks up until the start time.
	if(this->year == d->year){
		if(this->month == d->month){
			if(this->day == d->day){
				return false;
			}
			else if(this->day < d->day){
				return true;
			}
			else{
				return false;
			}
		}
		else if(this->month < d->month){
			return true;
		}
		else{
			return false;
		}
	}
	else if(this->year < d->year){
		return true;
	}
	else{
		return false;
	}
}

bool Date::equals(Date* d)
{
	if(this->year == d->year){
		if(this->month == d->month){
			if(this->day == d->day){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool Date::collides(Date* d, int stay)
{
	Date* tmpDate = new Date(d->day, d->month, d->year);
	Date* tmpThisDate = new Date(this->day, this->month, this->year);
	tmpDate->add(1);
	if(tmpDate->equals(tmpThisDate) == true){
		delete tmpDate;
		delete tmpThisDate;
		return true;
	}
	tmpDate->setDate(d->day, d->month, d->year);
	tmpThisDate->add(1);
	if(tmpThisDate->equals(tmpDate) == true){
		delete tmpDate;
		delete tmpThisDate;
		return true;
	}
	tmpThisDate->setDate(this->day, this->month, this->year);
	for(int i = 1 ; i <= stay; i++){
		tmpDate->add(1);
		tmpThisDate->setDate(this->day, this->month, this->year);
		for(int j = 1; j <= stay; j++){
			tmpThisDate->add(1);
			if(tmpDate->equals(tmpThisDate) == true){
				delete tmpDate;
				delete tmpThisDate;
				return true;
			}
		}
	}
	delete tmpDate;
	delete tmpThisDate;
	return false;
}
