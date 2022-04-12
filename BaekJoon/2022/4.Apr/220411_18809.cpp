#include <iostream>
#include <vector>
#include <utility>
#include <deque>

using namespace std;
int n, m, g, r;
const int INF = 1e9;
int answer = 0;
// 1 G, -1 R
int getFlower(vector<vector<int>> &garden, deque<pair<pair<int, int>, int>> deque, vector<vector<int>> visited)
{
  deque.push_back({{-1, -1}, 0});
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  int day = 2;
  int flower = 0;
  while (!deque.empty())
  {
    pair<pair<int, int>, int> cur = deque.front();
    int curx = cur.first.first;
    int cury = cur.first.second;
    int curc = cur.second;
    deque.pop_front();
    if (curx == -1)
    {
      if (deque.empty())
      {
        break;
      }
      day++;
      deque.push_back({{-1, -1}, 0});
      continue;
    }
    if (visited[curx][cury] == INF)
    {
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int nextx = curx + mx[i];
      int nexty = cury + my[i];
      if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m || garden[nextx][nexty] == 0)
      {
        continue;
      }
      if (visited[nextx][nexty] + curc * day == 0)
      {
        flower++;
        visited[nextx][nexty] = INF;
        continue;
      }
      if (visited[nextx][nexty] != 0)
      {
        continue;
      }
      visited[nextx][nexty] = curc * day;
      deque.push_back({{nextx, nexty}, curc});
    }
  }
  return flower;
}

void sow(vector<pair<int, int>> &culture, int cur, int curG, int curR, deque<pair<pair<int, int>, int>> &deque, vector<vector<int>> &garden, vector<vector<int>> &visited)
{
  if (curG == g && curR == r)
  {
    answer = max(answer, getFlower(garden, deque, visited));
    return;
  }
  if (cur >= culture.size())
  {
    return;
  }
  if (curG < g)
  {
    deque.push_back({culture[cur], 1});
    visited[culture[cur].first][culture[cur].second] = 1;
    sow(culture, cur + 1, curG + 1, curR, deque, garden, visited);
    visited[culture[cur].first][culture[cur].second] = 0;
    deque.pop_back();
  }
  if (curR < r)
  {
    deque.push_back({culture[cur], -1});
    visited[culture[cur].first][culture[cur].second] = -1;
    sow(culture, cur + 1, curG, curR + 1, deque, garden, visited);
    visited[culture[cur].first][culture[cur].second] = 0;
    deque.pop_back();
  }
  sow(culture, cur + 1, curG, curR, deque, garden, visited);
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> g >> r;
  vector<vector<int>> garden(n, vector<int>(m));
  deque<pair<pair<int, int>, int>> deque;
  vector<vector<int>> visited(n, vector<int>(m, 0));
  vector<pair<int, int>> culture;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> garden[i][j];
      if (garden[i][j] == 2)
      {
        culture.push_back({i, j});
      }
    }
  }

  sow(culture, 0, 0, 0, deque, garden, visited);
  cout << answer;
  return 0;
}