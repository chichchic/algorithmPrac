#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    n += 2;
    vector<pair<int, int>> points(n);
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
      cin >> points[i].first >> points[i].second;
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int distance = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
        if (distance <= 1000)
        {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    visited[0] = true;
    queue<int> que;
    que.push(0);
    bool happy = false;
    while (!que.empty())
    {
      int cur = que.front();
      if (cur == n - 1)
      {
        happy = true;
        break;
      }
      que.pop();
      for (int i = 0; i < graph[cur].size(); i++)
      {
        int next = graph[cur][i];
        if (!visited[next])
        {
          visited[next] = true;
          que.push(next);
        }
      }
    }
    if (happy)
      cout << "happy\n";
    else
      cout << "sad\n";
  }

  return 0;
}