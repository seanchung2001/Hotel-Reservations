#ifndef GUEST_H
#define GUEST_H

#include <string>
using namespace std;


class Guest
{
  public:
  	Guest(string="", bool=false);
  	string getName();
  	bool getIsPremium();
  	void addPts(int);
  	void print();
  	
  private:
  	string name;
  	bool isPremium;
  	int loyalPoints;
};

#endif
