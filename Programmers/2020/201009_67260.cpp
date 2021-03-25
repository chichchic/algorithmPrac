#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order)
{
  bool answer = true;
  vector<bool> hasKey(n, true);
  vector<bool> canGo(n, false);
  vector<bool> check(n, false);
  unordered_map<int, int> hash;
  for (int i = 0; i < order.size(); i++)
  {
    hasKey[order[i][1]] = false;
    hash.insert(make_pair(order[i][0], order[i][1]));
  }
  vector<vector<int>> path_tree(n);
  for (int i = 0; i < path.size(); i++)
  {
    path_tree[path[i][0]].push_back(path[i][1]);
    path_tree[path[i][1]].push_back(path[i][0]);
  }

  queue<int> que;
  que.push(0);
  int roomCnt = 0;
  canGo[0] = true;
  while (!que.empty())
  {
    int cur = que.front();
    que.pop();
    if (!hasKey[cur] || !canGo[cur] || check[cur])
      continue;
    check[cur] = true;
    roomCnt++;
    auto itr = hash.find(cur);
    if (itr != hash.end())
    {
      int room = hash[cur];
      hasKey[room] = true;
      if (canGo[room])
        que.push(room);
    }
    for (int i = 0; i < path_tree[cur].size(); i++)
    {
      int next = path_tree[cur][i];
      if (check[next])
        continue;
      canGo[next] = true;
      que.push(next);
    }
  }
  return roomCnt >= n;
}