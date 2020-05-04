#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct A
{
  vector<int> root;

  A(int n) : root(n + 1)
  {
    for (int i = 0; i <= n; i++)
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
    root[find(a)] = root[b];
  }
};

int n, m;

void connect(A &tree, char a, int i, int j)
{
  int x = i * m + j, y;
  if (a == 'D')
    y = (i + 1) * m + j;
  else if (a == 'R')
    y = i * m + j + 1;
  else if (a == 'L')
    y = i * m + j - 1;
  else
    y = (i - 1) * m + j;
  if (tree.find(x) != tree.find(y))
    tree.merge(x, y);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  cin >> n >> m;
  A tree(n * m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char a;
      cin >> a;
      connect(tree, a, i, j);
    }
  }

  unordered_map<int, int> map;
  for (int i = 0; i < n * m; i++)
  {
    int temp = tree.find(i);
    if (map.find(temp) == map.end())
    {
      map[temp] = 1;
    }
  }
  cout << map.size();
  return 0;
}