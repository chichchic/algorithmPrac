#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, t1, t2;
  cin >> n;
  vector<vi> tree(n + 1);
  vector<int> ans(n + 1);
  vector<bool> check(n + 1, false);
  for (int i = 0; i < n; i++)
  {
    scanf(" %d %d", &t1, &t2);
    tree[t1].push_back(t2);
    tree[t2].push_back(t1);
  }
  queue<int> q;
  q.push(1);
  check[1] = true;
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < tree[cur].size(); i++)
    {
      int temp = tree[cur][i];
      if (!check[temp])
      {
        check[temp] = true;
        ans[temp] = cur;
        q.push(temp);
      }
    }
  }
  for (int i = 2; i <= n; i++)
  {
    printf("%d\n", ans[i]);
  }

  return 0;
}