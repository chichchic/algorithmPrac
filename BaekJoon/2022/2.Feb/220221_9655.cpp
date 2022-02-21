#include <iostream>

using namespace std;

int dp[1001][3] = {{0, 0, 0}, {0, 1, 2}, {0, 2, 1}, {0, 1, 2}, {0, 2, 1}};

int winner(int n, int turn)
{
  if (dp[n][turn])
  {
    return dp[n][turn];
  }
  if (turn == 1) // SK
  {
    if (winner(n - 1, 2) == 1 && winner(n - 3, 2) == 1)
    {
      dp[n][turn] = 1;
      return 1;
    }
    dp[n][turn] = 2;
    return 2;
  }
  else // CY
  {
    if (winner(n - 1, 1) == 2 && winner(n - 3, 1) == 2)
    {
      dp[n][turn] = 2;
      return 2;
    }
    dp[n][turn] = 1;
    return 1;
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (winner(n, 1) == 1 ? "SK" : "CY");

  return 0;
}