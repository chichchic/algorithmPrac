#include <iostream>
#include <queue>

using namespace std;

int cleanArea[60][60];
bool clean[60][60];
int ans = 0;
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};

struct position
{
  int r;
  int c;
  int d; // 0: 북, 1: 동, 2: 남, 3: 서
};

int main()
{
  int n, m;
  cin >> n >> m;
  position cur;
  position next;

  cin >> cur.r >> cur.c >> cur.d;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> cleanArea[i][j];
    }
  }

  while (true)
  {
    bool doMove = false;
    if (cleanArea[cur.r][cur.c] == 0)
    {
      cleanArea[cur.r][cur.c] = 2;
      ans++;
    }
    for (int i = 0; i < 4; i++)
    {
      int newDirection = (cur.d + 3 - i) % 4;
      next = {cur.r + mx[newDirection],
              cur.c + my[newDirection],
              newDirection};
      if (cleanArea[next.r][next.c] == 0)
      {
        doMove = true;
        cur = next;
        break;
      }
    }
    if (!doMove)
    {
      next = {cur.r + mx[(cur.d + 2) % 4],
              cur.c + my[(cur.d + 2) % 4], cur.d};
      if (cleanArea[next.r][next.c] == 1)
        break;
      cur = next;
    }
  }
  cout << ans;
  return 0;
}