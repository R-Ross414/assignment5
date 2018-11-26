#include "DoubleListNode.h"
//#include <exception>

//class DLLException : public exception {};
//class DLLOutOfBounds : public DLLException {} outofbounds;

//this class represents a doubly linked list
template<class X> class DoublyLinkedList
{
  public:
    DoublyLinkedList(); //constructor
    DoublyLinkedList(X value);
    ~DoublyLinkedList(); //destructor

    /* These are the basic operations of a doubly linked list, manually coded:
      1. void method that adds node to the front of the list given data as
        a paramenter
      2. void method that adds node to the back of the list given data as
        a parameter
      3. function that removes the front node of the list
      4. function that removes the back node of the list
      5. removes node given a key value as a paramenter
      6. searches for data at a given node and returns it
      7. similar to peek, data can be returned from the front node of the
        list but not removed
      8. deletes node at a given position that is not front nor back
      9. search function for indexing and returning */
    void insertFront(X d); //#1
    void insertBack(X d); //#2
    X removeFront(); //#3
    X removeBack(); //#4
    ListNode<X> *remove(X key); //#5
    X find(X value); //#6
    X seeFront(); //#7
    X deletePos(int pos); //#8
    X get(int idx); //#9
    int Idx(X value);
    //check if method is greater than size

    /*10. void method that simply outputs (prints) the list
      11. returns size of the list as an integer*/
    void printList(); //#10
    unsigned int getSize(); //#11

    //manually created bubble sort method
    void BubbleSort(); //#12

    friend ostream& operator<<(ostream& os, DoublyLinkedList<X>& output)
    {
      if (output.front != NULL)
      {
        ListNode<X>* node = output.front;
        while (node != NULL)
        {
          os << node->data << " ";
          node = node->next;
        }
      }
      return os;
    }

  private:
    //These are the front and back nodes, as well as the size of the list
    ListNode<X> *front;
    ListNode<X> *back;
    unsigned int size;
};

/////////////////////////////////////////////////////////////////
////////////////****implementation****/////////////////////////
template <class X>
DoublyLinkedList<X>::DoublyLinkedList()
{
  front = NULL;
  back =  NULL;
  size = 0;
}

/////////////////////////////////////////////////////////////////
template <class X>
DoublyLinkedList<X>::DoublyLinkedList(X value)
{
  front = new ListNode<X>(value);
  back = NULL;
  size = 1;

}

/////////////////////////////////////////////////////////////////
template <class X>
DoublyLinkedList<X>::~DoublyLinkedList()
{
  if (front != NULL)
  {
    delete front;
    front = NULL;
  }
  if (back != NULL)
  {
    delete back;
    back = NULL;
  }
}

/////////////////////////////////////////////////////////////////
template <class X>
void DoublyLinkedList<X>::insertFront(X d)
{
  ListNode<X> *node = new ListNode<X>(d);
  if (size == 0) //empty list
  {
    back = node;
  }
  else //not empty
  {
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

/////////////////////////////////////////////////////////////////
template <class X>
void DoublyLinkedList<X>::insertBack(X d)
{
  ListNode<X> *node = new ListNode<X>(d);
  if (size == 0) //empty list
  {
    front = node;
  }
  else //not empty
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

/////////////////////////////////////////////////////////////////
template <class X>
X DoublyLinkedList<X>::removeFront()
{
  ListNode<X> *node = new ListNode<X>();
  ListNode<X> *temp = node;
  X data;
  //check if empty
  if(front->next == NULL) //only node in ListNode
  {
    back = NULL;
    temp = front;
    data = front->data;
    front = NULL;
  }
  else if(size == 0)
  {
    data = 0;
  }
  else //more than one node in list
  {
    data = front->data;
    temp = front;
    front = front->next;
    front->prev = NULL;
  }

  temp->next = NULL;

  data = temp->data;
  delete temp;
  size--;
  return data;
}

/////////////////////////////////////////////////////////////////
template <class X>
X DoublyLinkedList<X>::removeBack()
{
  ListNode<X> *temp = back;
  X data = temp->data;
  if(back == NULL)
  {

  }
  else
  {
    back = back->prev;
    back->next = NULL;
    delete temp;
  }
  size--;
  return data;
}

/////////////////////////////////////////////////////////////////
template <class X>
ListNode<X>* DoublyLinkedList<X>::remove(X key)
{
  ListNode<X> *current = front;
  while(current->data != key)
  {
    current = current->next;

    if(current = NULL)
    {
      return NULL;
    }
    //we found it
    if(current == front)
    {
      front = current->next;
    }
    else
    {
      current->prev->next = current->next;
    }

    if(current == back)
    {
      back = current->prev;
    }
    else
    {
      current->next->prev = current->prev;
      current->prev = NULL;
      --size;
      return current;
    }
  }
}

/////////////////////////////////////////////////////////////////
template <class X>
X DoublyLinkedList<X>::find(X value)
{
  int idx = -1;
  ListNode<X> *curr = front;

  while(curr != NULL) //begin searching for value
  {
    idx++;

    if(curr->data = value)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if(curr == NULL)
  {
    idx = -1;
  }
  return idx;
}

/////////////////////////////////////////////////////////////////
template <class X>
X DoublyLinkedList<X>::seeFront()
{
  return front->data;
}

/////////////////////////////////////////////////////////////////
template <class X>
X DoublyLinkedList<X>::deletePos(int pos)
{
  int idx = 0;

  ListNode<X> *curr = front;
  ListNode<X> *prev = front;

  while(idx != pos) //this loop is responsible for putting our pointers in their respective positions
  {
    cout << "hello world" << endl;
    prev = curr;
    curr = curr->next;
    ++idx;
  }

  //found the position, lets proceed to delete
  prev->next = curr->next;
  curr->next = NULL;

  X d = curr->data;
  cout << "goodbye world" << endl;
  size--;

  //delete curr;
  return d;
}

/////////////////////////////////////////////////////////////////
template <class X>
X DoublyLinkedList<X>::get(int idx)
{
  /*try
  {
    if (idx + 1 > getSize())
    {
      throw outofbounds;
    } */
    if (idx + 1 > getSize())
    {
      cout << "Out of bounds" << endl;
    }

    int pos = 0;
    ListNode<X>* node = front;

    while (pos < idx)
    {
      node = node->next;
      pos++;
    }
    return node->data;
  //}
  /*catch (DLLOutOfBounds e)
  {
    cout << "Out of bounds" << endl;
  }*/
}

/////////////////////////////////////////////////////////////////
template <class X>
int DoublyLinkedList<X>::Idx(X value)
{
  int idx = 0;
  ListNode<X>* node = front;

  while(node != NULL)
  {
    if (node->data == value)
    {
      break;
    }
    node = node->next;
    idx++;
  }
  if (node == NULL)
  {
    return -1;
  }
  return idx;
}
/////////////////////////////////////////////////////////////////
template <class X>
void DoublyLinkedList<X>::printList()
{
  ListNode<X> *curr = front;
  while(curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

/////////////////////////////////////////////////////////////////
template <class X>
unsigned int DoublyLinkedList<X>::getSize()
{
  return size;
}

/////////////////////////////////////////////////////////////////
template <class X>
void DoublyLinkedList<X>::BubbleSort()
{
  bool swap = false;
  ListNode<X>* ptr1;
  ListNode<X>* ptr2 = NULL;

  do
  {
    swap = false;
    ptr1 = front;

    while (ptr1->next != ptr2)
    {
      if (ptr1->data > ptr1->next->data)
      {
        X temp = ptr1->data;
        ptr1->data = ptr1->next->data;
        ptr1->next->data = temp;

        swap = true;
      }
      ptr1 = ptr1->next;
    }
    ptr2 = ptr1;
  }
  while (swap);
}
