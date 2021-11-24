#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> back(n + 1);
  vector<int> status(n + 1, 0);
  queue<int> que;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    back[a].push_back(b);
    status[b]++;
  }
  for (int i = 1; i <= n; i++)
  {
    if (status[i] == 0)
    {
      que.push(i);
    }
  }
  for (int i = 0; i < n; i++)
  {
    int cur = que.front();
    cout << cur << ' ';
    que.pop();
    for (int j = 0; j < back[cur].size(); j++)
    {
      int next = back[cur][j];
      if (--status[next] == 0)
      {
        que.push(next);
      }
    }
  }

  return 0;
}
