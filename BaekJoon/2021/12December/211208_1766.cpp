#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<bool> solved(n + 1, false);
  vector<vector<int>> link(n + 1);
  vector<int> count(n + 1, 0);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    link[a].push_back(b);
    count[b]++;
  }
  priority_queue<int, vector<int>, greater<int>> que;
  for (int i = 1; i <= n; i++)
  {
    if (count[i] == 0)
    {
      que.push(i);
    }
  }
  while (!que.empty())
  {
    int cur = que.top();
    que.pop();
    cout << cur << ' ';
    for (int i = 0; i < link[cur].size(); i++)
    {
      int next = link[cur][i];
      count[next]--;
      if (count[next] == 0)
      {
        que.push(next);
      }
    }
  }

  return 0;
}