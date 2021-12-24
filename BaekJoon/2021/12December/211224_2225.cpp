#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;

  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  for (int i = 0; i <= n; i++)
  {
    dp[i][1] = 1;
  }
  for (int i = 2; i <= k; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      for (int k = 0; k <= j; k++)
      {
        dp[j][i] = (dp[j][i] + dp[j - k][i - 1]) % MOD;
      }
    }
  }
  cout << dp[n][k];
  return 0;
}