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
    for (int i = 1; i <= n; i++)
    {
      root[i] = i;
    }
  }
  int find(int a)
  {
    if (root[a] == a)
      return a;
    else
      return root[a] = find(root[a]);
  }
  void merge(int a, int b)
  {
    root[find(a)] = root[b];
  }
};

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  A tree(n);
  int m;
  cin >> m;
  priority_queue<pipii> pq;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    pq.push(make_pair(-c, make_pair(a, b)));
  }
  int ans = 0;
  while (!pq.empty())
  {
    int a = pq.top().second.first;
    int b = pq.top().second.second;
    int val = -pq.top().first;
    pq.pop();
    if (tree.find(a) == tree.find(b))
      continue;
    ans += val;
    tree.merge(a, b);
  }
  cout << ans;
  return 0;
}