#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define infinity 999999999
using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pathes[n + 1];
  for (int i = 0; i < m; i++)
  {
    int s, e, cost;
    cin >> s >> e >> cost;
    pathes[s].push_back(make_pair(e, cost));
  }
  int start, end;
  cin >> start >> end;

  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  vector<int> move_cost(n + 1, infinity);
  move_cost[start] = 0;
  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int current = pq.top().second;
    if (current == end)
    {
      cout << cost;
      return 0;
    }
    pq.pop();
    for (int i = 0; i < pathes[current].size(); ++i)
    {
      int next = pathes[current][i].first;
      int nextCost = pathes[current][i].second;
      if (move_cost[next] > nextCost + cost)
      {
        move_cost[next] = nextCost + cost;
        pq.push(make_pair(-move_cost[next], next));
      }
    }
  }
  return 0;
}

/*
// NOTE: 재채점 결과 틀렸습니다로 변경됨
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct island
{
  vector<int> lend;
  vector<int> cost;
};

int dist[1003];
island bridge[1003];

int main()
{
  int n, m, startPoint, endPoint;
  bool lending = false;
  cin >> n >> m;
  fill(dist, dist + 1003, (1 << 31) - 1);
  for (int i = 0; i < m; i++)
  {
    int start, lend, cost;
    cin >> start >> lend >> cost;
    bridge[start].lend.push_back(lend);
    bridge[start].cost.push_back(cost);
  }

  cin >> startPoint >> endPoint;
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq; // cost, lend
  dist[startPoint] = 0;
  pq.push(make_pair(0, startPoint));

  while (!pq.empty())
  {
    pair<int, int> cur = pq.top();
    pq.pop();
    int target = cur.second;
    int targetCost = cur.first;
    for (int i = 0; i < bridge[target].lend.size(); i++)
    {
      if (dist[bridge[target].lend[i]] > targetCost + bridge[target].cost[i])
      {
        dist[bridge[target].lend[i]] = targetCost + bridge[cur.second].cost[i];
        pq.push(make_pair(dist[bridge[target].lend[i]], bridge[target].lend[i]));
      }
    }
  }
  cout << dist[endPoint];
  return 0;
}
*/
