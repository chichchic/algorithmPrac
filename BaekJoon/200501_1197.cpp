#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
  int n, e;
  cin >> n >> e;

  A tree(n);
  priority_queue<pair<int, pair<int, int>>> pq;

  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    pq.push(make_pair(-c, make_pair(a, b)));
  }

  int ans = 0;
  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;
    pq.pop();

    if (tree.find(a) == tree.find(b))
      continue;
    tree.merge(a, b);
    ans += cost;
  }
  cout << ans;
  return 0;
}