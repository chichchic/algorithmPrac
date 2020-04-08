#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

int ans = 987654321;

int n, m;
int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};

// void maze(vector<vi> &input, vector<vb> &check, int cnt, int x, int y)
// {
//   if (x == n - 1 && y == m - 1)
//   {
//     if (ans > cnt)
//       ans = cnt;
//     return;
//   }
//   for (int i = 0; i < 4; i++)
//   {
//     int nx = x + mx[i];
//     int ny = y + my[i];
//     if (nx >= 0 && ny >= 0 && nx < n && ny < m && input[nx][ny] == 1 && check[nx][ny] == false)
//     {
//       check[nx][ny] = true;
//       maze(input, check, cnt + 1, nx, ny);
//       check[nx][ny] = false;
//     }
//   }
// }

struct point
{
  int x, y, c;
  point(int a, int b, int cnt) : x(a), y(b), c(cnt){};
};

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
  vi inside(m);
  vector<vi> input(n, inside);
  vb binside(m, false);
  vector<vb> check(n, binside);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf(" %1d", &input[i][j]);
    }
  }
  check[0][0] = true;
  // maze(input, check, 1, 0, 0);
  queue<point> que;
  que.push(point(0, 0, 1));
  while (!que.empty())
  {
    point cur = que.front();
    que.pop();
    if (cur.x == n - 1 && cur.y == m - 1)
    {
      if (ans > cur.c)
        ans = cur.c;
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int nx = cur.x + mx[i];
      int ny = cur.y + my[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && input[nx][ny] == 1 && check[nx][ny] == false)
      {
        check[nx][ny] = true;
        que.push(point(nx, ny, cur.c + 1));
      }
    }
  }
  cout << ans;
  return 0;
}