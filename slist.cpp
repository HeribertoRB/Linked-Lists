// ====================================================
//HW#: HW3P3 slist
//Your name: Heriberto Bernal
//Complier:  gcc compiler
//File type: slist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"slist.h"

//PURPOSE: initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
  slist::slist()
{
  Front = NULL;
  Rear = NULL;
  count = 0;
}

slist::slist(const slist& Original)
{
  //  this->'s data members need to be initialized first
  this->Front = NULL;
  this->Rear = NULL;
  this->count = 0;

  //  this-> object has to be built up by allocating new cells and copying the values from Original into each cell 
    Node* P;  // local pointer for OtherOne
    P = Original.Front;
  while (P != NULL)  // This uses a loop which repeats until you reach the end of Original. 
    {
      this->addRear(P->Elem);    //P element is added to this->
      P = P->Next;               // Go to the next node in OtherOne   
    } 
    //  Nothing to return.
}

//PURPOSE: It will search for the key element in the slist
//PARAMETER: pass the key element to search it
int slist::search(el_t Key)
{
  if(isEmpty())
    return 0;
  else
    {
      Node *p; //node p element will be compared to Key
      p = Front;
      int i=1;
      while(p != NULL)
	{
	  if(p->Elem == Key)
	    return i; //return the number of the node that Key was found
	  else
	    {
	      p = p->Next;
	    }
	  i++;
	}
      return 0; //return 0 if Key was not found
    }
}

//PURPOSE: It will replace the element of the Ith Node
//PARAMETER: pass the element that will replace the current element, and pass the I integer to know which Node  
void slist::replace(el_t Elem, int I)
{
  if((I > count) || (I < 1))
    throw OutOfRange{};
  else
    {
      Node *p; //node p element will be replaced by Elem
      p = Front;
      int i=1;
      while(i != I)
	{
	  p = p->Next;
	  i++;
	}
      p->Elem = Elem;
    }
}

//PURPOSE: It will copy a list to another list
//PARAMETER: pass the list that will be copied to create another list
slist& slist::operator=(const slist& OtherOne)
{
  int eleme; //delete element will be placed here

  // make sure this-> and OtherOne are not the same object.
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(eleme);  

      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P.s element is added to this->
	  P = P->Next;               // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.
} 

//PURPOSE: it will check if two list have the same elements. True if they are the sanme, otherwise false.
//PARAMETER: pass the list that will be checked with the other list
bool slist::operator==(const slist& OtherOne)
{
  Node* p = this->Front; //p will point to first list front
  Node* q = OtherOne.Front; //q will point to second list front
  if((p == NULL) && (q == NULL)) //if both are empty, return true
    return true;
  else if(((p != NULL) && (q == NULL)) || ((p == NULL) && (q != NULL))) //if one has elements and the other one is empty, return false
    return false;
  else
    {
      while((p != NULL) && (q != NULL))
	{
	  if(p->Elem == q->Elem)
	    {
	      p = p->Next;
	      q = q->Next;
	    }
	  else
	    return false; //return false if the elements are not equal
	}
      if((p == NULL) && (q == NULL))//if they have the same elements, return true
	return true;
      else                         //if not, return false   
	return false;
    }
}
