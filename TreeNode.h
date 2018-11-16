#include <iostream>
using namespace std;

template<class X> class TreeNode
{
  public:
    TreeNode();
    TreeNode(X k);
    virtual ~TreeNode();

    int key;
    TreeNode<X> *left;
    TreeNode<X> *right;

    void printTree();
}
;
//////////////////////////////////////////////////////////////
template <class X>
TreeNode<X>::TreeNode()
{
  key = 0;
  left = NULL;
  right = NULL;
}

template <class X>
TreeNode<X>::TreeNode(X k)
{
  key = k;
  left = NULL;
  right = NULL;
}

template <class X>
TreeNode<X>::~TreeNode()
{

}

template <class X>
void TreeNode<X>::printTree()
{
  if (left != NULL)
  {
    left->printTree();
  }

  cout << key << endl;

  if (right != NULL)
  {
    right->printTree();
  }

}
