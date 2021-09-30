#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> scores(2, vector<int>(n + 1, 0));
    vector<vector<int>> dp(3, vector<int>(n + 1, 0));
    for (int i = 0; i < 2; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cin >> scores[i][j];
      }
    }
    dp[0][1] = scores[0][1];
    dp[1][1] = scores[1][1];
    int answer = max(dp[0][1], dp[1][1]);
    for (int i = 2; i <= n; i++)
    {
      dp[0][i] = scores[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
      dp[1][i] = scores[1][i] + max(dp[0][i - 1], dp[2][i - 1]);
      dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
      answer = max(max(answer, dp[0][i]), max(dp[1][i], dp[2][i]));
    }
    cout << answer << '\n';
  }

  return 0;
}