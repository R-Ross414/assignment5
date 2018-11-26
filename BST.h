#include "TreeNode.h"
#include <iostream>
using namespace std;

template<class X> class BST
{
  public:
    BST(); //CONSTRUCTOR
    BST(X value);
    virtual ~BST(); //DESTRUCTOR

    /*
    1) method used for destructor
    2) insert method for BST
    3) search method
    4) returns the successor node
    5) delete method for all node cases
    6) checks if tree is empty */
    void deleteAll(TreeNode<X>* node); //#1
    void insert(X value); //#2
    void insertPtr(X value);
    bool contains(X value); //#3
    bool containsPtr(X value);
    TreeNode<X>* getSuccessor(TreeNode<X> *d); //#4
    bool deleteRec(X k); //#5
    bool isEmpty(); //#6

    void printTree();
    void recPrint(X *node); //in-order traversal

    //remove ptr op (see delete rec) -- MAYBE?
    X search(X value);
    X searchPtr(X value);
    void printPtrTree();

    friend ostream& operator<<(ostream& os, BST<X>& output)
    {
      if (output.root != NULL)
      {
        os << *(output.root);
      }
      return os;
    };

  private:
    TreeNode<X> *root;
} ;

///////////////////////////////////////////////////////////////
/////////////////*****IMPLEMENTATION*****/////////////////////
template<class X>
BST<X>::BST()
{
  root = NULL;
  //root = new TreeNode<X>();
}

///////////////////////////////////////////////////////////////
template<class X>
BST<X>::BST(X value)
{
  root = new TreeNode<X>(value);
}

///////////////////////////////////////////////////////////////
template<class X>
BST<X>::~BST()
{
  deleteAll(root);
}

///////////////////////////////////////////////////////////////
template<class X>
void BST<X>::deleteAll(TreeNode<X>* node)
{
  if(node == NULL)
    {return;}
  deleteAll(node->left);
  deleteAll(node->right);
  delete node;
}

///////////////////////////////////////////////////////////////
template<class X>
void BST<X>::insert(X value)
{
  //check for duplicates
  TreeNode<X>* node = new TreeNode<X>(value);

  if (isEmpty())
  {
    root = node;
  }
  else //not an empty tree, find insertion point
  {
    TreeNode<X> *current = root;
    TreeNode<X> *parent; //empty tree node

    while(true)
    {
      parent = current;

      if (value < *(current->key))
        {
          current = current->left;
          if(current == NULL) //we found the insertion point
          {
            parent->left = node;
            break;
          }
        }
      else //go right
        {
          current = current->right;
          if(current == NULL) //we found the insertion point
          {
            parent->right = node;
            break;
          }
        }
    }
  }
}

///////////////////////////////////////////////////////////////
template<class X>
void BST<X>::insertPtr(X value)
{
  //check for duplicates
  TreeNode<X>* node = new TreeNode<X>(value);

  if (isEmpty())
  {
    root = node;
  }
  else //not an empty tree, find insertion point
  {
    TreeNode<X> *current = root;
    TreeNode<X> *parent; //empty tree node

    while(true)
    {
      parent = current;

      if (*value < **(current->key))
        {
          current = current->left;
          if(current == NULL) //we found the insertion point
          {
            parent->left = node;
            break;
          }
        }
      else //go right
        {
          current = current->right;
          if(current == NULL) //we found the insertion point
          {
            parent->right = node;
            break;
          }
        }
    }
  }
}
///////////////////////////////////////////////////////////////
//search method
template<class X>
bool BST<X>::contains(X value)
{
  if(isEmpty())
  {
    return false;
  }

  else //not an empty tree, continue the search
  {
    TreeNode<X> *current = root;

    while(*(current->key) != value)
    {
      if (current == NULL)
      {
        return false;
      }
      if (value < *(current->key))
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
  }
  return true;
}

///////////////////////////////////////////////////////////////
template<class X>
bool BST<X>::containsPtr(X value)
{
  if(isEmpty())
  {
    return false;
  }

  else //not an empty tree, continue the search
  {
    TreeNode<X> *current = root;

    do
    {
      if (*value < **(current->key))
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
      if (current == NULL)
      {
        return false;
      }
    } while(**(current->key) != *value);
  }
  return true;
}

///////////////////////////////////////////////////////////////
//d is the node we are deleting
template<class X>
TreeNode<X>* BST<X>::getSuccessor(TreeNode<X> *d)
{
  TreeNode<X> *sp = d;
  TreeNode<X> *success = d;
  TreeNode<X> *current = d->right;

  while (current != NULL)
  {
    sp = success;
    success = current;
    current = current->left;
  }

  if (success != d->right)
  {
    sp->left = success->right;
    success->right = d->right;
  }
  return success;
}

///////////////////////////////////////////////////////////////
template<class X>
bool BST<X>::deleteRec(X k)
{
  //use contains method
  if(!contains(k))
    return false;

  //lets proceed to find the TreeNode
  TreeNode<X> *current = root;
  TreeNode<X> *parent = root;
  bool isLeft = true;

  //lets look for the TreeNode
  while(*(current->key) != k)
  {
    parent = current;

    if(k < *(current->key))
    {
      isLeft = true;
      current = current->left;
    }
    else
    {
      isLeft = false;
      current = current->right;
    }

    if (current == NULL) //in the event you do not use contains
      return false;
  }

  //at this point we found the node to be deleted
  if(current->left == NULL && current->right == NULL)//then it's a leaf
  {
    if(current == root)
    {
      root = NULL;
    }
    else if (isLeft)
    {
      parent->left = NULL;
    }
    else
    {
      parent->right = NULL;
    }
  }

  //check if it has one child
  else if (current->right == NULL)//no right child, must be isLeft
  {
    if (current == root)
    {
      root = current->left;
    }
    else if (isLeft)
    {
      parent->left = current->left;
    }
    else //right child
    {
      parent->right = current->left;
    }
  }

  else //if it has 2 children we begin to cry and take a long nap
  {
    TreeNode<X> *successor = getSuccessor(current);

    if (current == root)
    {
      root = successor;
    }
    else if (isLeft)
    {
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }
    successor->left = current->left;
  }
  return true;
}

///////////////////////////////////////////////////////////////
template<class X>
bool BST<X>::isEmpty()
{
  return root == NULL;
}

///////////////////////////////////////////////////////////////
template<class X>
void BST<X>::printTree()
{
  if (root != NULL)
  {
    root->printTree();
  }
  cout << endl;
}

///////////////////////////////////////////////////////////////
template<class X>
void BST<X>::recPrint(X *node)
{
  if (node == NULL)
  {
    return;
  }

  recPrint(node->left);
  cout << node << endl;
  recPrint(node->right);
  cout << node << endl;
}
///////////////////////////
template<class X>
X BST<X>::search(X value)
{
    TreeNode<X> *current = root;

    while(*(current->key) != value)
    {
      if (current == NULL)
      {
        break;
      }
      if (value < *(current->key))
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    return *(current->key);
}

///////////////////////////
template<class X>
X BST<X>::searchPtr(X value)
{
  TreeNode<X> *current = root;

  while(**(current->key) != *value)
  {
    if (current == NULL)
    {
      break;
    }
    if (*value < **(current->key))
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  return *(current->key);
}

///////////////////////////
template<class X>
void BST<X>::printPtrTree()
{
  root->printPtrTree();
}

///////////////////////////
/*
template<class X>
ostream& operator<<(ostream& os, BST<X>& output)
{
  os << *(output.root);
  return os;
}*/
