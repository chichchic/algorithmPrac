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
  int n, m;
  cin >> n >> m;
  A tree(n + 1);
  for (int i = 0; i < m; i++)
  {
    int q, a, b;
    scanf(" %d %d %d", &q, &a, &b);
    if (q == 0)
    {
      tree.merge(a, b);
    }
    else
    {
      if (tree.find(a) == tree.find(b))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}