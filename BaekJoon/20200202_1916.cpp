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