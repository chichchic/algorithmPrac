/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
    queue<TreeNode *> que;
    TreeNode *tag;
    int ans = 0;
    if (root == NULL)
      return 0;
    que.push(root);
    que.push(tag);
    while (!que.empty())
    {
      TreeNode *temp = que.front();
      que.pop();
      if (temp == tag)
      {
        if (!que.empty())
          que.push(tag);
        ans++;
        continue;
      }
      if (temp->left != NULL)
      {
        que.push(temp->left);
      }
      if (temp->right != NULL)
      {
        que.push(temp->right);
      }
    }
    return ans;
  }
};