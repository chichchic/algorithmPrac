#include <iostream>
#include <queue>

using namespace std;

struct point
{
  int x, y;
  int can;
  int cnt;
  point(int a, int b, int c, int d) : x(a), y(b), can(c), cnt(d){};
};

int main()
{
  freopen("input.txt", "r", stdin);
  int n, m;
  int ans = 9999999;
  cin >> n >> m;

  int input[1001][10001];
  bool check[1001][1001][2] = {};

  int mx[4] = {1, -1, 0, 0};
  int my[4] = {0, 0, 1, -1};

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf(" %1d", &input[i][j]);
    }
  }

  queue<point> que;
  que.push(point(0, 0, 1, 1));
  check[0][0][1] = true;
  while (!que.empty())
  {
    int curx = que.front().x;
    int cury = que.front().y;
    int curc = que.front().can;
    int curcnt = que.front().cnt;
    que.pop();
    if (curx == n - 1 && cury == m - 1)
    {
      if (ans > curcnt)
        ans = curcnt;
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int nx = curx + mx[i];
      int ny = cury + my[i];
      if (nx < n && ny < m && nx >= 0 && ny >= 0 && check[nx][ny][curc] == false)
      {
        check[nx][ny][curc] = true;
        if (input[nx][ny] == 0)
        {
          que.push(point(nx, ny, curc, curcnt + 1));
        }
        else if (curc == 1)
        {
          que.push(point(nx, ny, curc - 1, curcnt + 1));
        }
      }
    }
  }
  if (ans == 9999999)
    cout << -1;
  else
    cout << ans;
  return 0;
}