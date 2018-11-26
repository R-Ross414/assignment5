#include <iostream>

using namespace std;
template<class X> class ListNode
{
  public:
    ListNode(); //constructor
    ListNode(X d); //overloaded constructor
    ~ListNode(); //destructor

    //Class variables
    X data; //data stored in node
    ListNode *next; //pointer to next node
    ListNode *prev; //pointer to previous node
};

////////////////////////////////////////////////////////////
////////////////****implementation****/////////////////////////

template<class X>
ListNode<X>::ListNode()
{ }

/////////////////////////////////////////////////////////////////
template<class X>
ListNode<X>::ListNode(X d)
{ //next and prev are null ptrs
  data = d;
  next = NULL;
  prev = NULL;
}

/////////////////////////////////////////////////////////////////
template<class X>
ListNode<X>::~ListNode()
{
  if (next != NULL)
  {
    delete next;
    next = NULL;
  }
  if (prev != NULL)
  {
    delete prev;
    prev = NULL;
  }
}
