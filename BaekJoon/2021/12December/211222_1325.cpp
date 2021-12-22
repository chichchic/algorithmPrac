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
  vector<vector<int>> reliable_computer(n + 1);
  vector<int> relialbe_cnt(n + 1, -1);
  int max_cnt = 0;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    reliable_computer[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
  {
    queue<int> que;
    vector<bool> visited(n + 1, false);
    que.push(i);
    int cnt = 1;
    visited[i] = true;
    while (!que.empty())
    {
      int cur = que.front();
      que.pop();
      for (int i = 0; i < reliable_computer[cur].size(); i++)
      {
        int next = reliable_computer[cur][i];
        if (visited[next])
          continue;
        visited[next] = true;
        que.push(next);
        cnt++;
      }
    }
    relialbe_cnt[i] = cnt;
    max_cnt = max(max_cnt, cnt);
  }
  for (int i = 1; i <= n; i++)
  {
    if (relialbe_cnt[i] == max_cnt)
    {
      cout << i << ' ';
    }
  }
  return 0;
}