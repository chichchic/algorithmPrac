#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int cheese_block = 1e9;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int melting(vector<vector<int>> &cheese, int time, int cheese_count)
{
  if (cheese_count == 0)
  {
    return time;
  }
  vector<vector<bool>> visited(cheese.size(), vector<bool>(cheese[0].size(), false));
  for (int i = 0; i < cheese.size(); i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int c = j == 0 ? 0 : cheese[0].size() - 1;
      if (!visited[i][c] && cheese[i][c] <= 0)
      {
        queue<pair<int, int>> que;
        que.push({c, i});
        visited[i][c] = true;
        cheese[i][c] = -1;
        while (!que.empty())
        {
          int cur_x = que.front().first;
          int cur_y = que.front().second;
          // cout << cur_x << ' ' << cur_y << '\n';
          que.pop();
          for (int d = 0; d < 4; d++)
          {
            int next_x = cur_x + dx[d];
            int next_y = cur_y + dy[d];
            if (next_x < 0 || next_y < 0 || next_x >= cheese.size() || next_y >= cheese[i].size() || visited[next_x][next_y] || cheese[next_x][next_y] > 0)
            {
              continue;
            }
            visited[next_x][next_y] = true;
            cheese[next_x][next_y] = -1;
            que.push({next_x, next_y});
          }
        }
      }
    }
  }
  for (int i = 0; i < cheese[0].size(); i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int c = j == 0 ? 0 : cheese.size() - 1;
      if (!visited[c][i] && cheese[c][i] <= 0)
      {
        queue<pair<int, int>> que;
        que.push({c, i});
        visited[c][i] = true;
        cheese[c][i] = -1;
        while (!que.empty())
        {
          int cur_x = que.front().first;
          int cur_y = que.front().second;
          que.pop();
          for (int d = 0; d < 4; d++)
          {
            int next_x = cur_x + dx[d];
            int next_y = cur_y + dy[d];
            if (next_x < 0 || next_y < 0 || next_x >= cheese.size() || next_y >= cheese[i].size() || visited[next_x][next_y] || cheese[next_x][next_y] > 0)
            {
              continue;
            }
            visited[next_x][next_y] = true;
            cheese[next_x][next_y] = -1;
            que.push({next_x, next_y});
          }
        }
      }
    }
  }
  for (int i = 0; i < cheese.size(); i++)
  {
    for (int j = 0; j < cheese[i].size(); j++)
    {
      if (cheese[i][j] != 1)
        continue;
      int contact = 0;
      for (int k = 0; k < 4; k++)
      {
        int side_x = i + dx[k];
        int side_y = j + dy[k];
        if (side_x < 0 || side_y < 0 || side_x >= cheese.size() || side_y >= cheese[i].size() || cheese[side_x][side_y] >= 0)
        {
          continue;
        }
        contact++;
        if (contact >= 2)
        {
          break;
        }
      }
      if (contact >= 2)
      {
        cheese[i][j] = 0;
        cheese_count--;
      }
    }
  }
  return melting(cheese, time + 1, cheese_count);
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cheese(n, vector<int>(m));
  int cheese_count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> cheese[i][j];
      if (cheese[i][j] == 1)
        cheese_count++;
    }
  }

  cout << melting(cheese, 0, cheese_count) << '\n';
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << cheese[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  return 0;
}