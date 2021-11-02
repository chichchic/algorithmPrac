#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

set<pair<int, int>> clean_air(vector<vector<int>> &dust, vector<pair<int, int>> &air_cleaner, set<pair<int, int>> dust_position)
{
  int mx1[4] = {0, -1, 0, 1};
  int my1[4] = {1, 0, -1, 0};
  int status1 = 0;
  int x1 = air_cleaner[0].first + mx1[status1];
  int y1 = air_cleaner[0].second + my1[status1];
  int prev_dust1 = 0;
  while (true)
  {
    if (dust[x1][y1] == -1)
    {
      break;
    }
    int temp = prev_dust1;
    prev_dust1 = dust[x1][y1];
    dust[x1][y1] = temp;
    if (temp > 0)
    {
      dust_position.insert({x1, y1});
    }
    else
    {
      dust_position.erase({x1, y1});
    }
    int nx1 = x1 + mx1[status1];
    int ny1 = y1 + my1[status1];
    if (nx1 < 0 || nx1 > air_cleaner[0].first || ny1 < 0 || ny1 >= dust[0].size())
    {
      status1++;
      x1 += mx1[status1];
      y1 += my1[status1];
    }
    else
    {
      x1 = nx1;
      y1 = ny1;
    }
  }
  int mx2[4] = {0, 1, 0, -1};
  int my2[4] = {1, 0, -1, 0};
  int status2 = 0;
  int x2 = air_cleaner[1].first + mx2[status2];
  int y2 = air_cleaner[1].second + my2[status2];
  int prev_dust2 = 0;
  while (true)
  {
    if (dust[x2][y2] == -1)
    {
      break;
    }
    int temp = prev_dust2;
    prev_dust2 = dust[x2][y2];
    dust[x2][y2] = temp;
    if (temp > 0)
    {
      dust_position.insert({x2, y2});
    }
    else
    {
      dust_position.erase({x2, y2});
    }
    int nx2 = x2 + mx2[status2];
    int ny2 = y2 + my2[status2];
    while (nx2 < air_cleaner[1].first || nx2 >= dust.size() || ny2 < 0 || ny2 >= dust[0].size())
    {
      status2 = (status2 + 1) % 4;
      nx2 = x2 + mx2[status2];
      ny2 = y2 + my2[status2];
    }
    x2 = nx2;
    y2 = ny2;
  }
  return dust_position;
}

vector<vector<int>> spreadDust(vector<vector<int>> &dust, set<pair<int, int>> &dust_position)
{
  vector<vector<int>> output(dust.size(), vector<int>(dust[0].size(), 0));
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  for (auto iter : dust_position)
  {
    int cur_x = iter.first;
    int cur_y = iter.second;
    int spread_dust_amount = dust[cur_x][cur_y] / 5;
    for (int j = 0; j < 4; j++)
    {
      if (spread_dust_amount == 0)
        break;
      int next_x = cur_x + mx[j];
      int next_y = cur_y + my[j];
      if (next_x < 0 || next_y < 0 || next_x >= dust.size() || next_y >= dust[0].size() || dust[next_x][next_y] == -1)
      {
        continue;
      }
      dust_position.insert({next_x, next_y});
      output[next_x][next_y] += spread_dust_amount;
      dust[cur_x][cur_y] -= spread_dust_amount;
      if (dust[cur_x][cur_y] == 0)
      {
        dust_position.erase({cur_x, cur_y});
      }
    }
    output[cur_x][cur_y] += dust[cur_x][cur_y];
  }
  return output;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r, c, t;
  cin >> r >> c >> t;
  vector<vector<int>> dust(r, vector<int>(c));
  set<pair<int, int>> dust_position;
  vector<pair<int, int>> air_cleaner;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> dust[i][j];
      if (dust[i][j] > 0)
      {
        dust_position.insert({i, j});
      }
      if (dust[i][j] < 0)
      {
        air_cleaner.push_back({i, j});
      }
    }
  }

  while (t--)
  {
    dust = spreadDust(dust, dust_position);
    dust[air_cleaner[0].first][air_cleaner[0].second] = -1;
    dust[air_cleaner[1].first][air_cleaner[1].second] = -1;
    dust_position = clean_air(dust, air_cleaner, dust_position);
  }
  int answer = 0;
  for (auto r : dust)
  {
    for (auto c : r)
    {
      if (c != -1)
        answer += c;
    }
  }
  cout << answer;
  return 0;
}