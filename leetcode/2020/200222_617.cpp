/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

class Solution
{
public:
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
  {

    if (t1 == NULL && t2 == NULL)
    {
      return NULL;
    }
    else if (t1 != NULL && t2 != NULL)
    {
      t1->val += t2->val;
      t1->left = mergeTrees(t1->left, t2->left);
      t1->right = mergeTrees(t1->right, t2->right);
      return t1;
    }
    else if (t1 != NULL && t2 == NULL)
    {
      return t1;
    }
    else
    {
      return t2;
    }
  }
};