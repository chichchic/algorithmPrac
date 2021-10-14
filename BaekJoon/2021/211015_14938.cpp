#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, r;
  int answer = 0;
  cin >> n >> m >> r;
  vector<int> item(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> item[i];
  }
  vector<vector<pair<int, int>>> edges(n + 1);
  for (int i = 0; i < r; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
  for (int i = 1; i <= n; i++)
  {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, 1e9);
    dist[i] = 0;
    pq.push({0, i});
    while (!pq.empty())
    {
      int cur = pq.top().second;
      int len = -pq.top().first;
      pq.pop();
      for (int i = 0; i < edges[cur].size(); i++)
      {
        int next = edges[cur][i].first;
        if (dist[next] > len + edges[cur][i].second)
        {
          dist[next] = len + edges[cur][i].second;
          pq.push({-dist[next], next});
        }
      }
    }
    int item_point = 0;
    for (int i = 1; i <= n; i++)
    {
      if (dist[i] <= m)
      {
        item_point += item[i];
      }
    }
    answer = max(answer, item_point);
  }
  cout << answer;
  return 0;
}