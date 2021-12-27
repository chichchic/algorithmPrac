#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<vector<char>> forest(r, vector<char>(c));
  vector<vector<bool>> visited(r, vector<bool>(c, false));
  queue<pair<int, int>> move;
  queue<pair<int, int>> water;
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  move.push({-1, -1});
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> forest[i][j];
      if (forest[i][j] == 'S')
      {
        move.push({i, j});
        visited[i][j] = true;
      }
      else if (forest[i][j] == '*')
      {
        water.push({i, j});
      }
    }
  }
  int answer = 0;
  water.push({-1, -1});

  while (!move.empty())
  {
    int cx = move.front().first;
    int cy = move.front().second;
    move.pop();
    if (cx == -1)
    {
      if (move.empty())
      {
        break;
      }
      move.push({-1, -1});
      answer++;
      while (!water.empty())
      {
        int wx = water.front().first;
        int wy = water.front().second;
        water.pop();
        if (wx == -1)
        {
          water.push({-1, -1});
          break;
        }
        for (int i = 0; i < 4; i++)
        {
          int nwx = wx + mx[i];
          int nwy = wy + my[i];
          if (nwx < 0 || nwx >= r || nwy < 0 || nwy >= c || forest[nwx][nwy] == 'D' || forest[nwx][nwy] == 'X' || forest[nwx][nwy] == '*')
          {
            continue;
          }
          forest[nwx][nwy] = '*';
          water.push({nwx, nwy});
        }
      }
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int ncx = cx + mx[i];
      int ncy = cy + my[i];
      if (ncx < 0 || ncx >= r || ncy < 0 || ncy >= c || visited[ncx][ncy] || forest[ncx][ncy] == '*' || forest[ncx][ncy] == 'X')
      {
        continue;
      }
      if (forest[ncx][ncy] == 'D')
      {
        cout << answer;
        return 0;
      }
      visited[ncx][ncy] = true;
      move.push({ncx, ncy});
    }
  }
  cout << "KAKTUS";
  return 0;
}