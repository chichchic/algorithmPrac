#include <iostream>
#include <queue>

using namespace std;
int tBox[1003][1003];
bool check[1003][1003];

struct cur
{
  int y;
  int x;
  int ans;
};

int main()
{
  int m, n, ans = 0;
  cin >> m >> n;
  int total = m * n;
  int cnt = 0;
  int mx[4] = {-1, 1, 0, 0};
  int my[4] = {0, 0, -1, 1};

  queue<cur> que;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> tBox[i][j];
      if (tBox[i][j] == 1)
      {
        cnt++;
        cur temp = {j, i, 0};
        que.push(temp);
        check[i][j] = true;
      }
      else if (tBox[i][j] == -1)
        total--;
    }
  }

  while (!que.empty())
  {
    int cAns = que.front().ans;
    if (ans < cAns)
      ans = cAns;
    if (cnt == total)
      break;
    int x = que.front().x;
    int y = que.front().y;

    if (tBox[x][y] == 0)
    {
      tBox[x][y] = 1;
      cnt++;
    }

    que.pop();

    for (int i = 0; i < 4; i++)
    {
      cur temp = {y + my[i], x + mx[i], cAns + 1};
      if (!check[temp.x][temp.y] && temp.x >= 0 && temp.x < n && temp.y >= 0 && temp.y < m && tBox[temp.x][temp.y] == 0)
      {
        que.push(temp);
        check[temp.x][temp.y] = true;
      }
    }
  }

  if (cnt == total)
    cout << ans << '\n';
  else
    cout << -1 << '\n';
  return 0;
}