// =======================================================
// HW#: HW3P3 slist
// Your name: Heriberto Bernal
// Compiler:  g++
// File type: headher file
//=======================================================

#include "llist.h" //Include this file to inherit funcions

class slist: public llist //class slist will inherit function from class llist
{
 public:
  slist(); //constructor to create a list object
  slist(const slist& Original); //Constructor to create a list object copying another one

  //PURPOSE: It will search for a specific Node
  //PARAMETER: pass the key element to know which number will it searchs
  int search(el_t Key);
  
  //PURPOSE: It will replace an element from a node
  //PARAMETER: pass the element that will replace the current element, and pass the I integer to know which node 
  void replace(el_t Elem, int I);

  //PURPOSE: It will copy a list to another list
  //PARAMETER: pass the list that will be copied to create another list
  slist& operator=(const slist& OtherOne);

  //PURPOSE: it will check if two list have the same elements. True if they are the sanme, otherwise false.
  //PARAMETER: pass the list that will be checked with the other list
  bool operator==(const slist& OtherOne);
};
