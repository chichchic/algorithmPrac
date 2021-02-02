#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

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

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  while (n != 0 && m != 0)
  {

    A tree(n);

    priority_queue<pipii> pq;
    int total = 0;
    for (int i = 0; i < m; i++)
    {
      int a, b, c;
      scanf(" %d %d %d", &a, &b, &c);
      total += c;
      pq.push(make_pair(-c, make_pair(a, b)));
    }
    int ans = 0;
    while (!pq.empty())
    {
      int dist = -pq.top().first;
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      pq.pop();
      if (tree.find(x) == tree.find(y))
        continue;
      ans += dist;
      tree.merge(x, y);
    }
    cout << total - ans << '\n';
    cin >> n >> m;
  }
  return 0;
}