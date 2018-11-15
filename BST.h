#include "TreeNode.h"
#include <iostream>
using namespace std;

class BST
{
  public:
    BST();
    virtual ~BST();

    void deleteAll(TreeNode* node);
    void insert(int value);
    bool contains(int value);
    bool deleteNode(int value);
    TreeNode* getSuccessor(TreeNode *d);
    bool deleteRec(int k);
    bool isEmpty();

    void printTree();
    void recPrint(TreeNode *node); //in-order traversal

  private:
    TreeNode *root;
} ;

///////////////////////////////////////////////////////////////
BST::BST()
{

}

BST::~BST()
{
  deleteAll(root);
}

void BST::deleteAll(TreeNode* node)
{
  if(node == NULL)
    {return;}
  deleteAll(node->left);
  deleteAll(node->right);
  delete node;
}

void BST::printTree()
{
  root->printTree();
  cout << endl;
}

bool BST::isEmpty()
{
  return root == NULL;
}

void BST::recPrint(TreeNode *node)
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

void BST::insert(int value)
{
  //check for duplicates

  TreeNode *node = new TreeNode(value);

  if (isEmpty())
  {
    root = node;
  }
  else //not an empty tree, find insertion point
  {
    TreeNode *current = root;
    TreeNode *parent; //empty tree node

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
bool BST::contains(int value)
{
  if(isEmpty())
  {
    return false;
  }

  else //not an empty tree, continue the search
  {
    TreeNode *current = root;

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
TreeNode* BST::getSuccessor(TreeNode *d)
{
  TreeNode *sp = d;
  TreeNode *success = d;
  TreeNode *current = d->right;

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

bool BST::deleteRec(int k)
{
  //use contains method

  if(!contains(k))
    return false;

  //lets proceed to find the TreeNode
  TreeNode *current = root;
  TreeNode *parent = root;
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
    TreeNode *successor = getSuccessor(current);

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
