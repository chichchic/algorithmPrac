#include <iostream>
#include <vector>

using namespace std;

struct A
{
  vector<int> root;
  A(int n) : root(n + 1)
  {
    for (int i = 1; i <= n; i++)
    {
      root[i] = i;
    }
  }

  int find(int n)
  {
    if (root[n] == n)
      return n;
    return root[n] = find(root[n]);
  }

  void merge(int a, int b)
  {
    root[find(a)] = find(b);
  }
};

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  A tree(n + 1);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int temp;
      scanf(" %d", &temp);
      if (temp == 1)
        tree.merge(i, j);
    }
  }

  int a, b;
  cin >> a;
  for (int i = 1; i < m; i++)
  {
    scanf(" %d", &b);
    if (tree.find(a) != tree.find(b))
    {
      cout << "NO";
      return 0;
    }
    a = b;
  }
  cout << "YES";
  return 0;
}