#include "TreeNode.h"
#include <iostream>
using namespace std;

template<class X> class BST
{
  public:
    BST();
    virtual ~BST();

    void deleteAll(X* node);
    void insert(X value);
    bool contains(X value);
    bool deleteNode(X value);
    TreeNode<X>* getSuccessor(X *d);
    bool deleteRec(X k);
    bool isEmpty();

    void printTree();
    void recPrint(X *node); //in-order traversal

  private:
    TreeNode<X> *root;
} ;

///////////////////////////////////////////////////////////////
template<class X>
BST<X>::BST()
{

}

template<class X>
BST<X>::~BST()
{
  deleteAll(root);
}

template<class X>
void BST<X>::deleteAll(X* node)
{
  if(node == NULL)
    {return;}
  deleteAll(node->left);
  deleteAll(node->right);
  delete node;
}

template<class X>
void BST<X>::printTree()
{
  root->printTree();
  cout << endl;
}

template<class X>
bool BST<X>::isEmpty()
{
  return root == NULL;
}

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

template<class X>
void BST<X>::insert(X value)
{
  //check for duplicates

  X *node = new TreeNode<X>(value);

  if (isEmpty())
  {
    root = node;
  }
  else //not an empty tree, find insertion point
  {
    X *current = root;
    X *parent; //empty tree node

    while(true)
    {
      parent = current;

      if (value < current->key)
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
    X *current = root;

    while(current->key != value)
    {
      if (current == NULL)
      {
        return false;
      }
      if (value < current->key)
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

//d is the node we are deleting
template<class X>
TreeNode<X>* BST<X>::getSuccessor(X *d)
{
  X *sp = d;
  X *success = d;
  X *current = d->right;

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

template<class X>
bool BST<X>::deleteRec(X k)
{
  //use contains method

  if(!contains(k))
    return false;

  //lets proceed to find the TreeNode
  X *current = root;
  X *parent = root;
  bool isLeft = true;

  //lets look for the TreeNode
  while(current->key != k)
  {
    parent = current;

    if(k < current->key)
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
    X *successor = getSuccessor(current);

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
