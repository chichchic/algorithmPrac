#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long dp[91][2] = {};
  dp[1][1] = 1;
  dp[2][0] = 1;
  dp[2][1] = 0;
  int n;
  cin >> n;
  for (int i = 3; i <= n; i++)
  {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }
  cout << dp[n][0] + dp[n][1];

  return 0;
}