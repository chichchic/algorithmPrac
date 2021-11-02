#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

int getSector(vector<vector<char>> &image, unordered_map<char, int> color_group)
{
  vector<vector<int>> visited(image.size(), vector<int>(image.size(), false));
  queue<pair<int, int>> que;
  int output = 0;
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  for (int x = 0; x < image.size(); ++x)
  {
    for (int y = 0; y < image.size(); ++y)
    {
      if (visited[x][y])
        continue;
      visited[x][y] = true;
      output++;
      que.push({x, y});
      int group_kind = color_group.find(image[x][y])->second;
      while (!que.empty())
      {
        int curX = que.front().first;
        int curY = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
          int nextX = curX + mx[i];
          int nextY = curY + my[i];
          if (nextX < 0 || nextY < 0 || nextX >= image.size() || nextY >= image.size() ||
              visited[nextX][nextY] || color_group.find(image[nextX][nextY])->second != group_kind)
            continue;
          visited[nextX][nextY] = true;
          que.push({nextX, nextY});
        }
      }
    }
  }
  return output;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<char>> image(n, vector<char>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> image[i][j];
    }
  }
  unordered_map<char, int> non_color_week;
  non_color_week.insert({'R', 1});
  non_color_week.insert({'G', 2});
  non_color_week.insert({'B', 3});
  unordered_map<char, int> color_week;
  color_week.insert({'R', 1});
  color_week.insert({'G', 1});
  color_week.insert({'B', 2});
  cout << getSector(image, non_color_week) << ' ' << getSector(image, color_week);
  return 0;
}