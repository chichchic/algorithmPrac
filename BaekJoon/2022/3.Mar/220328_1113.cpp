#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int maxh = 0;
int ground[50][50] = {};

bool fillWater(int x, int y, int h)
{
  vector<vector<bool>> visited(51, vector<bool>(51, false));
  queue<pair<int, int>> que;
  que.push({x, y});
  visited[x][y] = true;
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  while (!que.empty())
  {
    int curx = que.front().first;
    int cury = que.front().second;
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int nextx = curx + mx[i];
      int nexty = cury + my[i];
      if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
      {
        return false;
      }
      if (visited[nextx][nexty] || ground[nextx][nexty] >= h)
      {
        continue;
      }
      visited[nextx][nexty] = true;
      que.push({nextx, nexty});
    }
  }
  return true;
}

int main()
{
  //freopen("./input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%1d", &ground[i][j]);
      maxh = max(maxh, ground[i][j]);
    }
  }
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int amount = 0;
      for (int k = ground[i][j]; k <= maxh; k++)
      {
        if (fillWater(i, j, k))
        {
          amount = k - ground[i][j];
        }
      }
      answer += amount;
    }
  }
  cout << answer;
  return 0;
}