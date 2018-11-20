#include <iostream>
using namespace std;

template<class X> class TreeNode
{
  public:
    TreeNode(); //DEFAULT CONSTRUCTOR
    TreeNode(X k); //OVERLOADED CONSTRUCTOR
    virtual ~TreeNode(); //DESTRUCTOR

    X* key; //KEY TO NODE
    TreeNode<X> *left; //LEFT NODE
    TreeNode<X> *right; //RIGHT NODE

    void printTree(); //SELF EXPLANATORY
}
;
///////////////////////////////////////////////////////////////
/////////////////*****IMPLEMENTATION*****/////////////////////
template <class X>
TreeNode<X>::TreeNode()
{
  key = NULL;
  left = NULL;
  right = NULL;
}

///////////////////////////////////////////////////////////////
template <class X>
TreeNode<X>::TreeNode(X k)
{
  key = new X(k);
  left = NULL;
  right = NULL;
}

///////////////////////////////////////////////////////////////
template <class X>
TreeNode<X>::~TreeNode()
{
  if (key != NULL)
  {
    delete key;
  }
  if (left != NULL)
  {
    delete left;
  }
  if (right != NULL)
  {
    delete right;
  }
}

///////////////////////////////////////////////////////////////
template <class X>
void TreeNode<X>::printTree()
{
  if (left != NULL)
  {
    left->printTree();
  }

  if (key != NULL)
  {
    cout << *key << endl;    
  }

  if (right != NULL)
  {
    right->printTree();
  }
}
