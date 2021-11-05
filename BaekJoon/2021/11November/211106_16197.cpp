#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<vector<bool>> blocked(n, vector<bool>(m, false));
  vector<vector<bool>> visited1(n, vector<bool>(m, false));
  vector<vector<bool>> visited2(n, vector<bool>(m, false));
  char input;
  bool getFirstCoint = false;
  int fx, fy, sx, sy;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> input;
      if (input == 'o')
      {
        if (!getFirstCoint)
        {
          getFirstCoint = true;
          fx = i;
          fy = j;
        }
        else
        {
          sx = i;
          sy = j;
        }
      }
      else if (input == '#')
      {
        blocked[i][j] = true;
      }
    }
  }
  queue<pair<pair<int, int>, pair<int, int>>> que;
  que.push({{fx, fy}, {sx, sy}});
  que.push({{-1, -1}, {-1, -1}});
  int count = 0;
  while (!que.empty())
  {
    int cfx = que.front().first.first;
    int cfy = que.front().first.second;
    int csx = que.front().second.first;
    int csy = que.front().second.second;
    que.pop();
    if (cfx == -1)
    {
      count++;
      if (count == 10)
      {
        cout << -1;
        return 0;
      }
      que.push({{-1, -1}, {-1, -1}});
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int nfx = cfx + mx[i];
      int nfy = cfy + my[i];
      int nsx = csx + mx[i];
      int nsy = csy + my[i];

      bool move1 = true;
      int out1 = 0;
      bool move2 = true;
      int out2 = 0;
      if (nfx >= 0 && nfy >= 0 && nfx < n && nfy < m)
      {
        if (blocked[nfx][nfy])
        {
          move1 = false;
          nfx = cfx;
          nfy = cfy;
        }
      }
      else
      {
        out1 = 1;
      }
      if (nsx >= 0 && nsy >= 0 && nsx < n && nsy < m)
      {
        if (blocked[nsx][nsy])
        {
          move2 = false;
          nsx = csx;
          nsy = csy;
        }
      }
      else
      {
        out2 = 1;
      }
      if (out1 ^ out2)
      {
        cout << count + 1;
        return 0;
      }
      if (!move1 && !move2)
      {
        continue;
      }
      if (out1 | out2)
      {
        continue;
      }
      if (nfx == nsx && nfy == nsy)
      {
        continue;
      }
      que.push({{nfx, nfy}, {nsx, nsy}});
    }
  }
  cout << -1;
  return 0;
}