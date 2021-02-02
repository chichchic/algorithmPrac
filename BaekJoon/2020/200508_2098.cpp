#include <iostream>
#include <cstring>

using namespace std;

int cost[17][17], dp[17][1 << 17], n;

int f(int vtx, int state)
{
  int &ret = dp[vtx][state];
  if (ret != -1)
    return ret;

  if (state == (1 << n) - 1)
  {
    if (cost[vtx][0] == 0)
      return 1e9;
    return cost[vtx][0];
  }

  ret = 1e9;
  for (int i = 0; i < n; i++)
  {
    if (state & (1 << i) || cost[vtx][i] == 0)
      continue;
    ret = min(ret, f(i, state | (1 << i)) + cost[vtx][i]);
  }
  return ret;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> cost[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << f(0, 1);
  return 0;
}