#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int eat_fish(vector<vector<int>> &space, pair<int, int> &shark, const int shark_state)
{
  queue<pair<int, pair<int, int>>> que;
  bool find_fish = false;
  que.push(make_pair(0, shark));
  pair<int, pair<int, int>> fish_position = {1e9, {-1, -1}};
  int mx[4] = {1, -1, 0, 0};
  int my[4] = {0, 0, 1, -1};
  vector<vector<bool>> visited(space.size(), vector<bool>(space.size(), false));
  visited[shark.first][shark.second] = true;
  while (!que.empty())
  {
    int step = que.front().first;
    int curX = que.front().second.first;
    int curY = que.front().second.second;
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int nextX = curX + mx[i];
      int nextY = curY + my[i];
      if (nextX < 0 || nextY < 0 || nextX >= space.size() || nextY >= space.size() || visited[nextX][nextY])
        continue;
      visited[nextX][nextY] = true;
      int space_state = space[nextX][nextY];
      if (space_state > shark_state)
        continue;
      if (space_state == 0 || space_state == shark_state)
        que.push({step + 1, {nextX, nextY}});
      else
      {
        find_fish = true;
        if (fish_position.first > step + 1)
        {
          fish_position = {step + 1, {nextX, nextY}};
        }
        else if (fish_position.first == step + 1)
        {
          if (fish_position.second.first > nextX)
          {
            fish_position = {step + 1, {nextX, nextY}};
          }
          else if (fish_position.second.first == nextX)
          {
            if (fish_position.second.second > nextY)
            {
              fish_position = {step + 1, {nextX, nextY}};
            }
          }
        }
      }
    }
  }
  if (fish_position.first != 1e9)
  {
    space[fish_position.second.first][fish_position.second.second] = 0;
    shark = fish_position.second;
    return fish_position.first;
  }
  return 0;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> space(n, vector<int>(n));
  pair<int, int> shark;
  int shark_state = 2;
  int eat_count = 0;
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> space[i][j];
      if (space[i][j] == 9)
      {
        shark = {i, j};
        space[i][j] = 0;
      }
    }
  }

  while (true)
  {
    int time = eat_fish(space, shark, shark_state);
    if (time == 0)
      break;
    eat_count++;
    answer += time;
    if (eat_count == shark_state)
    {
      shark_state++;
      eat_count = 0;
    }
  }
  cout << answer;
  return 0;
}