#include <iostream>

using namespace std;
int dp[301][301] = {};

int getTime(int x, int y)
{
  if (x == 1 && y == 1)
  {
    return 0;
  }
  if (x == 1)
  {
    return y - 1;
  }
  if (y == 1)
  {
    return x - 1;
  }
  if (dp[x][y] != 0)
  {
    return dp[x][y];
  }
  int x1, x2, y1, y2;
  x1 = x / 2;
  x2 = x - x1;
  return dp[x][y] = getTime(x1, y) + getTime(x2, y) + 1;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  cout << getTime(x, y);

  return 0;
}