#include <iostream>

struct Node
{
  int value;
  struct Node *left;
  struct Node *right;
};

using namespace std;

void print_post_order(struct Node *node)
{
  if (node->left != nullptr)
  {
    print_post_order(node->left);
  }
  if (node->right != nullptr)
  {
    print_post_order(node->right);
  }
  cout << node->value << '\n';
}

struct Node *insert_pre_order(struct Node *node, int value)
{
  if (node == nullptr)
  {
    node = new Node();
    node->left = nullptr;
    node->right = nullptr;
    node->value = value;
    return node;
  }
  if (node->value > value)
  {
    node->left = insert_pre_order(node->left, value);
  }
  else
  {
    node->right = insert_pre_order(node->right, value);
  }
  return node;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  struct Node *root = nullptr;
  while (cin >> n)
  {
    root = insert_pre_order(root, n);
  }

  print_post_order(root);

  return 0;
}