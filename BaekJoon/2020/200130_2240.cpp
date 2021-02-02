#include <iostream>

using namespace std;

int dp[1001][31];

int main()
{
  // freopen("input.txt", "r", stdin);
  int t, w;
  int temp;
  int ans = 1;
  cin >> t >> w;
  for (int i = 1; i <= t; i++)
  {
    cin >> temp;
    temp--;
    dp[i][0] = dp[i - 1][0];
    if (!temp)
      dp[i][0]++;
    ans = max(ans, dp[i][0]);
    for (int j = 1; j <= i && j <= w; j++)
    {
      int plus[2] = {};
      plus[temp]++;
      dp[i][j] = max(dp[i - 1][j] + plus[j % 2], dp[i - 1][j - 1] + plus[j % 2]);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
  return 0;
}