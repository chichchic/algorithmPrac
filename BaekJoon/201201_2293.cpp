#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int dp[2][10001] = {
      0,
  };
  dp[0][0] = 1;
  dp[1][0] = 1;

  int n, k;
  cin >> n >> k;

  int coinValue[101];
  for (int i = 1; i <= n; i++)
  {
    cin >> coinValue[i];
  }

  bool firstNeg = false;
  for (int i = 1; i <= n; i++)
  {
    int pre, cur;
    if (i % 2 == 1)
    {
      pre = 0;
      cur = 1;
    }
    else
    {
      pre = 1;
      cur = 0;
    }

    for (int j = 0; j <= k; j++)
    {
      if (j < coinValue[i])
      {
        dp[cur][j] = dp[pre][j];
      }
      else
      {
        dp[cur][j] = dp[pre][j] + dp[cur][j - coinValue[i]];
      }
      // cout << dp[cur][j] << ' ' << i << ' ' << j << '\n';
    }
  }
  if (n %= 2)
    cout << dp[1][k];
  else
    cout << dp[0][k];
  return 0;
}