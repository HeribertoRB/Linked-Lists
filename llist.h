
// =======================================================
// HW#: HW3P1 llist
// Your name: Heriberto Berna;
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  count;        // counter for the number of nodes
  
 public:
  // Exception handling classes 
  class Underflow{};   // thrown when the llist underflows
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: It will check if the llist is empty
  bool isEmpty();
    
  //PURPOSE: If not empty, it will display all elements in the llist
  void displayAll();

  //PURPOSE: It will add a node to the front of the llist
  //PARAMETER: pass the element to be added
  void addFront(el_t);
    
  //PURPOSE: It will add a node to the rear of the llist
  //PARAMETER: pass the element to be added
  void addRear(el_t);

  //PURPOSE: If not empty, it will delete the front node; otherwise, throws an exception
  //PARAMETER: provide variable to receive the deleted element( pass by ref)
  void deleteFront(el_t&);
    
  //PURPOSE: If not empty, it will delete the rear node; otherwise, throws an exception
  //PARAMETER: provide variable to receive the deleted element (pass by ref)
  void deleteRear(el_t&);
    
  //PURPOSE: if not empty, it will delete the I node (chose by client); otherwise, throws an exception. If I is less than 1 or greater the count throw an exception.
  //PARAMETER: provide variable to receive the deleted element (pass by ref), and pass the number to know which node will be deleted
  void deleteIth(int I, el_t&);

  //PURPOSE: It will added a node before the I node (chose by client). If I is less than 1 pr I is greater than count+1 throw an exception. 
  //PARAMETER: pass the element to be added, and pass the number to know the node before the I node
  void addbeforeIth(int I, el_t);
};
