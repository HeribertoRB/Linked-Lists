//=========================================================
//HW#: HW3EC slist
//Your name: Heriberto Bernal
//Complier:  gcc compiler
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This program will create two linked list and will check if they are the same
//ALgoritgm/Design: it will check each element in both linked list and compare them. If all elements are the same or if both list are empty, then the lists are the same. Otherwise they are different 
int main()
{
  slist L1, L2;
  int counter = 1;
  int same;
  int eleme;
  
  //1.L1 is empty and L2 is empty
  cout << counter << endl; counter++;
  cout << "L1 is empty and L2 is empty     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  //2.L1 is empty and L2 has 2 elements 
  L2.addRear(1);
  L2.addRear(2);
  cout << counter << endl; counter++;
  cout << "L1 is empty and L2 has 2 elements     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;
  
  //3.L1 has 2 elements and L2 is empty
  L2.deleteRear(eleme);
  L2.deleteRear(eleme);
  L1.addRear(1);
  L1.addRear(2);
  cout << counter << endl; counter++;
  cout << "L1 has 2 elements and L2 is empty     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  //4.L1 has 1,2,3 and L2 has 1,2,3
  L1.addRear(3);
  L2.addRear(1);
  L2.addRear(2);
  L2.addRear(3);
  cout << counter << endl; counter++;
  cout << "L1 has 1,2,3 and L2 has 1,2,3     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  //5.L1 has 1,2,3 and L2 has 1,2
  L2.deleteRear(eleme);
  cout << counter << endl; counter++;
  cout << "L1 has 1,2,3 and L2 has 1,2     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  //6.L1 has 1,2,3 and L2 has 1,2,3,4
  L2.addRear(3);
  L2.addRear(4);
  cout << counter << endl; counter++;
  cout << "L1 has 1,2,3 and L2 has 1,2,3,4     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  //7.L1 has 1,2,3 and L2 has 1,2,4 
  L2.deleteIth(3, eleme);
  cout << counter << endl; counter++;
  cout << "L1 has 1,2,3 and L2 has 1,2,4     ";
  same = (L1 == L2);
  if(same == 1)
    cout << "True" << endl;
  else
    cout << "False" << endl;

}//end of program
