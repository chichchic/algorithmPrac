#include <iostream>
#include <cstring>

using namespace std;

int cost[17][17], dp[17][1 << 17], n, p;
char run[17];

int f(int vtx, int state, int cnt)
{
  if (state == (1 << n) - 1 || cnt >= p)
  {
    if (cnt == p)
      return 0;
    else
      return 1e9;
  }
  int &ret = dp[vtx][state];
  if (ret != -1)
    return ret;
  ret = 1e9;

  for (int i = 0; i < n; i++)
  {
    if (state & (1 << i))
      continue;
    if (run[i] == 'N')
      ret = min(ret, f(i, state | 1 << i, cnt));
    else
    {
      int mini = 1e9;
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        ret = min()
      }
    }
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> cost[i][j];
    }
  }
  scanf(" %s", run);
  memset(dp, -1, sizeof(dp));
  cin >> p;
  cout << run;
  return 0;
}