#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<char, char>> v(30);

void preorder(char vtx)
{
  cout << vtx;
  if (v[vtx - 'A'].first != '.')
    preorder(v[vtx - 'A'].first);
  if (v[vtx - 'A'].second != '.')
    preorder(v[vtx - 'A'].second);
}

void inorder(char vtx)
{
  if (v[vtx - 'A'].first != '.')
    inorder(v[vtx - 'A'].first);
  cout << vtx;
  if (v[vtx - 'A'].second != '.')
    inorder(v[vtx - 'A'].second);
}

void postorder(char vtx)
{
  if (v[vtx - 'A'].first != '.')
    postorder(v[vtx - 'A'].first);
  if (v[vtx - 'A'].second != '.')
    postorder(v[vtx - 'A'].second);
  cout << vtx;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    char root, left, right;
    cin >> root >> left >> right;
    v[root - 'A'] = make_pair(left, right);
  }
  preorder('A');
  cout << '\n';
  inorder('A');
  cout << '\n';
  postorder('A');
  return 0;
}