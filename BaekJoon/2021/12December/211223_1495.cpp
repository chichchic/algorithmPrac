#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, s, m;
  cin >> n >> s >> m;
  vector<int> gap(n + 1);
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
  for (int i = 1; i <= n; i++)
  {
    cin >> gap[i];
  }
  dp[0][s] = true;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (!dp[i - 1][j])
      {
        continue;
      }
      if (j - gap[i] >= 0)
      {
        dp[i][j - gap[i]] = true;
      }
      if (j + gap[i] <= m)
      {
        dp[i][j + gap[i]] = true;
      }
    }
  }
  for (int j = m; j >= 0; j--)
  {
    if (dp[n][j])
    {
      cout << j;
      return 0;
    }
  }
  cout << -1;
  return 0;
}