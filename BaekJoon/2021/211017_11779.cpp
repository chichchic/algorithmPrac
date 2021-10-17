#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> print_answer(vector<pair<int, int>> &dist, stack<int> &output, int cur_pos)
{
  while (cur_pos >= 0)
  {
    output.push(cur_pos);
    cur_pos = dist[cur_pos].second;
  }
  return output;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<unordered_map<int, int>> bus_info(n + 1);
  for (int i = 0; i < m; i++)
  {
    int s, e, c;
    cin >> s >> e >> c;
    if (bus_info[s].find(e) != bus_info[s].end())
    {
      bus_info[s][e] = min(bus_info[s][e], c);
    }
    else
    {
      bus_info[s][e] = c;
    }
  }
  int answer_start, answer_end;
  cin >> answer_start >> answer_end;
  priority_queue<pair<int, int>> pq;

  vector<pair<int, int>> dist(n + 1, {1e9 + 1, -1});
  dist[answer_start] = {0, -1};
  pq.push({0, answer_start});
  while (!pq.empty())
  {
    int cur_cost = -pq.top().first;
    int cur_pos = pq.top().second;
    if (cur_pos == answer_end)
    {
      cout << cur_cost << '\n';
      stack<int> output;
      print_answer(dist, output, cur_pos);
      cout << output.size() << '\n';
      while (!output.empty())
      {
        cout << output.top() << ' ';
        output.pop();
      }
      return 0;
    }
    pq.pop();
    for (auto iter : bus_info[cur_pos])
    {
      int next_pos = iter.first;
      int next_cost = iter.second + cur_cost;
      if (dist[next_pos].first > next_cost)
      {
        dist[next_pos].first = next_cost;
        dist[next_pos].second = cur_pos;
        pq.push({-next_cost, next_pos});
      }
    }
  }

  return 0;
}