#include <iostream>
using namespace std;

class TreeNode
{
  public:
    TreeNode();
    TreeNode(int k);
    virtual ~TreeNode();

    int key;
    TreeNode *left;
    TreeNode *right;

    void printTree();
}
;
//////////////////////////////////////////////////////////////
TreeNode::TreeNode()
{
  key = 0;
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(int k)
{
  key = k;
  left = NULL;
  right = NULL;
}

TreeNode::~TreeNode()
{

}

void TreeNode::printTree()
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
