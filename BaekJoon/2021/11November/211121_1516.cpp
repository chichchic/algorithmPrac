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

  int n;
  cin >> n;
  priority_queue<pair<int, int>> que;
  vector<vector<int>> build(n + 1);
  vector<int> linkStatus(n + 1, 0);
  vector<int> buildTime(n + 1);
  vector<int> answer(n + 1, -1);
  for (int i = 1; i <= n; i++)
  {
    cin >> buildTime[i];

    int before;
    cin >> before;
    while (before != -1)
    {
      build[before].push_back(i);
      linkStatus[i]++;
      cin >> before;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (linkStatus[i] == 0)
    {
      que.push({-buildTime[i], i});
      answer[i] = buildTime[i];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    int cur = que.top().second;
    que.pop();
    for (int j = 0; j < build[cur].size(); j++)
    {
      int parentNum = build[cur][j];
      if (--linkStatus[parentNum] == 0)
      {
        answer[parentNum] = answer[cur] + buildTime[parentNum];
        que.push({-answer[parentNum], parentNum});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << answer[i] << '\n';
  }
  return 0;
}