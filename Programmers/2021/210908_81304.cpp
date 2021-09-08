#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps)
{
  vector<int> isTrap(n + 1, -1);
  for (int idx = 0; idx < traps.size(); idx++)
  {
    isTrap[traps[idx]] = idx;
  }
  vector<piii> roadMap[n + 1];
  for (int i = 0; i < roads.size(); ++i)
  {
    int s = roads[i][0];
    int e = roads[i][1];
    int w = roads[i][2];
    piii temp1 = make_pair(e, make_pair(w, 0));
    piii temp2 = make_pair(s, make_pair(w, 1));
    roadMap[s].push_back(temp1);
    roadMap[e].push_back(temp2);
  }
  vector<vector<int>> visited(n + 1, vector<int>(1 << (traps.size() + 1), false));
  priority_queue<piii> pq;
  pq.push(make_pair(0, make_pair(start, 0)));
  while (!pq.empty())
  {
    auto top = pq.top();
    pq.pop();
    int weight = top.first;
    int cur = top.second.first;
    int state = top.second.second;
    visited[cur][state] = true;
    if (cur == end)
    {
      return -weight;
    }
    int curType = 0;
    if (isTrap[cur] != -1 && (state & (1 << isTrap[cur])))
    {
      curType = 1;
    }
    for (int i = 0; i < roadMap[cur].size(); ++i)
    {
      int e = roadMap[cur][i].first;
      int w = roadMap[cur][i].second.first;
      int roadType = roadMap[cur][i].second.second;
      int nextType = 0;
      int nextState = state;
      if (isTrap[e] != -1)
      {
        nextState = state ^ (1 << isTrap[e]);
        nextType = (state & (1 << isTrap[e])) ? 1 : 0;
      }
      if ((curType ^ nextType) != roadType)
        continue;
      if (visited[e][nextState])
        continue;
      pq.push(make_pair(weight - w, make_pair(e, nextState)));
    }
  }
  return 0;
}