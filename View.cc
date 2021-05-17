#include <iostream>
using namespace std;
#include <string>

#include "View.h"

/*
Purpose of this program:
Acts as the display portion of our project. Displays a menu in which the user can interact with.

Complex or critical data members:

showMenu(int&): Shows a menu of operations we can compute. The user will enter the number corresponding to the operation they would like to compute. This function will loop over until the user enters a valid choice.

printStr(string): Prints the string specified in the parameter to the terminal.

readInt(int&): Reads in and stores an integer.

readStr(string&): Reads in and stores the string.
*/

void View::showMenu(int& choice)
{
  int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print reservations" << endl;
  cout << "  (2) Print room information" << endl;
  cout << "  (3) Print guest information" << endl;
  cout << "  (4) Print event records" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}
