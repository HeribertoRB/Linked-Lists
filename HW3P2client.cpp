
//=========================================================
//HW#: HW3P2 slist
//Your name: Heriberto Bernal
//Complier:  gcc compiler
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: This program will create a linked list
//Algorithm/Design: It will call different functions to modify or display the linked list 
int main()
{ slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
try
  {
    //  1)add to front once (element 4)
    cout << counter << endl; counter++;
    L.addFront(4);

    //  2)add to rear 3 times (elements 6,7,8)
    cout << counter << endl; counter++;
    L.addRear(6);
    L.addRear(7);
    L.addRear(8);

    //  3)displayAll    - 4 6 7 8
    cout << counter << endl; counter++;
    L.displayAll();

    //  4)search for 6, report the result  - found in pos 2
    cout << counter << endl; counter++;
    foundPos = L.search(6);
    if(foundPos == 0)
      cout << "not found" << endl;
    else
      {
	cout << "found in pos " << foundPos << endl;
      }
    //  5)replace the 6 with 0 using the search result
    cout << counter << endl; counter++;
    L.replace(0, foundPos);

    //  6)search for 8 and report the result . found in pos 4
    cout << counter << endl; counter++;
    foundPos = L.search(8);
    if(foundPos == 0)
      cout << "not found" << endl;
    else
      {
        cout << "found in pos " << foundPos << endl;
      }

    //  7)replace the 8 with 2 using the search result
    cout << counter << endl; counter++;
    L.replace(2, foundPos);

    //  8)displayAll                       - 4 0 7 2
    cout << counter << endl; counter++;
    L.displayAll();

    //  9)search for 5 and report the result   - not found
    cout << counter << endl; counter++;
    foundPos = L.search(5);
    if(foundPos == 0)
      cout << "not found" << endl;
    else
      {
        cout << "found in pos " << foundPos << endl;
      }

    // 10) replace postion 7 with 10
    cout << counter << endl; counter++;
    L.replace(10, foundPos);
    }//end of try
 catch(slist::OutOfRange)
    { cout << "ERROR: Bad position was given" << endl;}

}//end of program
