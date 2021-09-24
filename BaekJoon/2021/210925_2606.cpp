#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int computer, line_cnt;
  cin >> computer >> line_cnt;
  vector<vector<int>> graph(computer + 1);
  for (int i = 0; i < line_cnt; i++)
  {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<bool> visited(computer + 1, false);
  visited[1] = true;

  queue<int> que;
  que.push(1);
  while (!que.empty())
  {
    int cur = que.front();
    que.pop();
    for (int i = 0; i < graph[cur].size(); ++i)
    {
      int next = graph[cur][i];
      if (visited[next])
        continue;
      que.push(next);
      visited[next] = true;
    }
  }
  int answer = 0;
  for (bool is_visited : visited)
  {
    if (is_visited)
      answer++;
  }
  cout << answer - 1;
  return 0;
}