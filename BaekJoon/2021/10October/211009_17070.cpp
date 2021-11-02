#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<int> mx1[3];
vector<int> mx2[3];
vector<int> my1[3];
vector<int> my2[3];
vector<int> mtype[3];
vector<vector<pair<int, int>>> typeArea(3);
int move_pipe(const int n, vector<vector<int>> &map, int x1, int y1, int x2, int y2, int type)
{
  int output = 0;
  for (int i = 0; i < mtype[type].size(); i++)
  {
    int nx1 = x1 + mx1[type][i];
    int ny1 = y1 + my1[type][i];
    int nx2 = x2 + mx2[type][i];
    int ny2 = y2 + my2[type][i];
    if (nx1 >= n || ny1 >= n || nx2 >= n || ny2 >= n)
      continue;
    bool can_move = true;
    for (int j = 0; j < typeArea[mtype[type][i]].size(); j++)
    {
      int cx = x2 + typeArea[mtype[type][i]][j].first;
      int cy = y2 + typeArea[mtype[type][i]][j].second;
      if (map[cx][cy] == 1)
      {
        can_move = false;
        break;
      }
    }
    if (!can_move)
    {
      continue;
    }
    if (nx2 == n - 1 && ny2 == n - 1)
    {
      return 1;
    }
    output += move_pipe(n, map, nx1, ny1, nx2, ny2, mtype[type][i]);
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
  vector<vector<int>> map(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[j][i];
    }
  }
  mx1[0] = {1, 1};
  my1[0] = {0, 0};
  mx2[0] = {1, 1};
  my2[0] = {0, 1};
  mtype[0] = {0, 2};
  mx1[1] = {0, 0};
  my1[1] = {1, 1};
  mx2[1] = {0, 1};
  my2[1] = {1, 1};
  mtype[1] = {1, 2};
  mx1[2] = {1, 1, 1};
  my1[2] = {1, 1, 1};
  mx2[2] = {1, 0, 1};
  my2[2] = {0, 1, 1};
  mtype[2] = {0, 1, 2};
  typeArea[0] = {{1, 0}};
  typeArea[1] = {{0, 1}};
  typeArea[2] = {{1, 0}, {0, 1}, {1, 1}};
  if (map[n - 1][n - 1] == 1)
  {
    cout << 0;
  }
  else
  {
    cout << move_pipe(n, map, 0, 0, 1, 0, 0);
  }
  return 0;
}