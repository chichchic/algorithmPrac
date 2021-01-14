#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
  int answer = 0;
  vector<vector<int>> dp(m, vector<int>(n, -1));
  dp[0][0] = 1;
  for (int i = 0; i < puddles.size(); i++)
  {
    dp[puddles[i][0] - 1][puddles[i][1] - 1] = 0;
  }
  for (int i = 1; i < n; i++)
  {
    if (dp[0][i] == 0)
      continue;
    dp[0][i] = dp[0][i - 1];
  }
  for (int i = 1; i < m; i++)
  {
    if (dp[i][0] == 0)
      continue;
    dp[i][0] = dp[i - 1][0];
  }
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (dp[i][j] == 0)
        continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
    }
  }
  return dp[m - 1][n - 1];
}