
// ====================================================
//HW#: HW3P1 llist
//Your name: Heriberto Bernal
//Complier:  gcc compiler
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//PURPOSE: initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  count = 0;
}

//PURPOSE: while the list is not empty, call deleteFront repeatedly to delete all nodes.
llist::~llist()
{
  int num; //the element of the deleted node will be place here
  cout << "Calling the llist destructor..." << endl;
  while(!isEmpty())
    {
      deleteFront(num);
    }    
}  

//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0; otherwise return false.
bool llist::isEmpty()
{
  if((count == 0) && (Front == NULL) && (Rear == NULL))
    return true;
  else
    return false;
}

//PURPOSE: Special case: if the list is empty, display [ empty ] ).
//       Regular: displays each element of the list horizontally starting from Front in [ ].
void llist::displayAll()
{
  if(isEmpty())
    cout << "[ empty ]" << endl;
  else
    {
      Node *p; //node p will be displayed 
      p = Front;
      while(p != NULL)
	{
	  cout << "[ " << p-> Elem << " ]" << endl;
	  p = p->Next;
	}
    }
}

//PURPOSE: Special case: if this is going to be the very first node, a new node will be created and Front and Rear point to it. Place NewNum and Count is updated.
//    Regular: adds a new node at the rear and puts NewNum in the Elem field of this new node. Count is updated.
//PARAMETER: pass the element to be added
void llist::addRear(el_t NewNum) 
{
  if (isEmpty())
    { //Special case:
      Node *P = new Node; //new node p will be added to the rear
	P-> Elem = NewNum;
	P-> Next = NULL;
	Front = P;
	Rear = P;
	count++;
      }
      else
	{
	  //Regular case:
	  Rear->Next = new Node; // new node will be added to the rear
	  Rear = Rear->Next;
	  Rear->Elem = NewNum;
	  Rear->Next = NULL;
	  count++;
	}
}

//PURPOSE: Special case: if this is going to be the very first node, a new node will be created and Front and Rear point to it. Place NewNum and Count is updated.
//    Regular: add a new node to the front of the list and Count is updated.
//PARAMETER: pass the element to be added
void llist::addFront(el_t NewNum)
{
  if(isEmpty())
    {//Special case:
      Node *p = new Node; //new node p will be added to the fornt
      p-> Elem = NewNum;
      p-> Next = NULL;
      Front = p;
      Rear = p;
      count++;
    }
  else
    {//Regular case:
      Node *x; //new node x will be added to the front
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      count++;
    }
}

//PURPOSE:  Error case: if the List is empty, throw Underflow
//- Special case: if currently only one Node, give back the front node element through OldNum (pass by reference) and  both Front and Rear become NULL. Count is updated.
//  - Regular: give back the front node element through OldNum (pass by reference) and also removes the front node.Count is updated.
//PARAMETER: provide a holder for the element deleted (pass by ref)
void llist::deleteFront(el_t& OldNum)
{
  if(isEmpty()) //Error case
	{
	  throw Underflow{};
	}
  else if(count == 1)//special case
	  {
	    OldNum = Front-> Elem;
	    Rear = NULL;
	    delete Front; //delete the front node
	    Front = Rear;
	    count--;
	  }
  else //Regular case
	{
	  OldNum = Front->Elem;
	  Node *Second; //the will become the new front node 
	  Second = Front->Next;
	  delete Front; //delete current front node
	  Front = Second;
	  count--;
	}
}

//PURPOSE: - Error case: if empty, throw Underflow
//- Special case: if currently only one node, give back the rear node element through OldNum (pass by reference) and both Front and Rear become NULL. Count is updated.
//  - Regular: give back the rear node element through OldNum (pass by reference) and also remove the rear node. Count is updated.
//PARAMETER: provide a holder for the element deleted (pass by ref)
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty())//Error case:
    {
      throw Underflow{};
    }
  else if(count == 1)//Special case:
    {
      OldNum = Rear->Elem;
      Front = NULL;
      delete Rear; //delete rear node
      Rear = Front;
      count--;
    }
  else// Regular case:
    {
      OldNum = Rear->Elem;
      Node *p; //this will become the new rear node
      p = Front;
      while(p->Next != Rear)
	{
	  p = p->Next;
	}
      delete Rear; //delete current rear node
      Rear = p;
      Rear->Next = NULL;
      count--;
    }
}

//PURPOSE: - Error case: If I is an illegal value (I > Count or I < 1) throw OutOfRange.
//- Special cases: this  call deleteFront when I is 1 or deleteRear when I is Count.
//- Regular: delete the Ith node (I starts out at 1).  Count is updated.
//PARAMETER: provide a holder for the element deleted (pass by ref), and pass the element to know which node
void llist::deleteIth(int I, el_t& OldNum)
{
  if((I > count) || (I < 1))//Error case:
    throw OutOfRange{};
  else if(I == 1)//Special case #1:
    deleteFront(OldNum);
  else if(I == count)//Spacial case #2:
    deleteRear(OldNum);
  else//Regular case:
    {
      Node *p; //this node Next will point to the deleted Next node
      Node *q; //this node will be deleted
      p = Front;
      q = p->Next;
      for(int i=2; i<I; i++)
        {
          p = q;
          q = p->Next;
        }
      OldNum = q->Elem;
      p->Next = q->Next;
      delete q; //delete the I node
      count--;
    }
}

//PURPOSE: - Error case: If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
//-  Special cases: this call addFront when I is 1 or addRear when I is Count+1
//-  Regular: add right before the Ith node. Count if updated.
//PARAMETER: provide a holder for the element deleter (pass by ref), and pass the element to know which node
void llist::addbeforeIth(int I, el_t newNum)
{
  if((I > count+1) || (I < 1))//Error case:
    throw OutOfRange{};
  else if(I == 1)//Special case #1:
    addFront(newNum);
  else if(I == count+1)//Special case #2:
    addRear(newNum);
  else//Regular case:
    {
      Node *p; //this node Next will point to the added new node
      Node *q; //the new node Next will point to this node
      p = Front;
      q = p->Next;
      for(int i=2; i<I; i++)
	{
	  p = q;
	  q = p->Next;
	}
      Node *x = new Node; //this node will be added
      x->Elem = newNum;
      p->Next = x;
      x->Next = q;
      count++;
    }
}

