#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map)
{
  vector<vector<int>> dp(m, vector<int>(n, 0));
  dp[0][0] = 1; //(m,n)
  for (int i = 1; i < n; i++)
  {
    if (city_map[0][i] == 1)
      continue;
    dp[0][i] = dp[0][i - 1];
  }
  for (int i = 1; i < m; i++)
  {
    if (city_map[i][0] == 1)
      continue;
    dp[i][0] = dp[i - 1][0];
  }
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (city_map[i][j] == 1)
        continue;
      int up = i - 1;
      int upVal = 0;
      while (up >= 0)
      {
        if (city_map[up][j] != 2)
        {
          upVal = dp[up][j];
          break;
        }
        up--;
      }
      int left = j - 1;
      int leftVal = 0;
      while (left >= 0)
      {
        if (city_map[i][left] != 2)
        {
          leftVal = dp[i][left];
          break;
        }
        left--;
      }
      dp[i][j] = (upVal + leftVal) % MOD;
    }
  }
  return dp[m - 1][n - 1];
}