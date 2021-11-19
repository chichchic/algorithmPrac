#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
int answer = 1e5;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

bool isSideline(int x, int y, vector<vector<int>> world_map)
{
  if (x + 1 < n && world_map[x + 1][y] == 0)
  {
    return true;
  }
  if (y + 1 < n && world_map[x][y + 1] == 0)
  {
    return true;
  }
  if (x - 1 >= 0 && world_map[x - 1][y] == 0)
  {
    return true;
  }
  if (y - 1 >= 0 && world_map[x][y - 1] == 0)
  {
    return true;
  }
  return false;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<vector<int>> world_map(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> world_map[i][j];
    }
  }
  int world_cnt = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (world_map[i][j] == 1)
      {
        world_cnt++;
        queue<pair<int, int>> que;
        world_map[i][j] = world_cnt;
        que.push({i, j});
        while (!que.empty())
        {
          int cur_x = que.front().first;
          int cur_y = que.front().second;
          que.pop();
          for (int i = 0; i < 4; i++)
          {
            int next_x = cur_x + mx[i];
            int next_y = cur_y + my[i];
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n || world_map[next_x][next_y] != 1)
              continue;
            world_map[next_x][next_y] = world_cnt;
            que.push({next_x, next_y});
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (world_map[i][j] == 0)
      {
        continue;
      }
      if (!isSideline(i, j, world_map))
      {
        continue;
      }
      int cur_island = world_map[i][j];
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      queue<pair<int, int>> que;
      int candidate = 0;
      que.push({i, j});
      visited[i][j] = true;
      que.push({-1, -1});
      while (!que.empty() && candidate < answer)
      {
        int cur_x = que.front().first;
        int cur_y = que.front().second;
        que.pop();
        if (cur_x == -1)
        {
          candidate++;
          que.push({-1, -1});
          continue;
        }
        for (int i = 0; i < 4; i++)
        {
          int next_x = cur_x + mx[i];
          int next_y = cur_y + my[i];
          if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n ||
              visited[next_x][next_y] || world_map[next_x][next_y] == cur_island)
            continue;
          if (world_map[next_x][next_y] > 2)
          {
            answer = min(answer, candidate);
            break;
          }
          visited[next_x][next_y] = true;
          que.push({next_x, next_y});
        }
      }
    }
  }
  cout << answer;
  return 0;
}