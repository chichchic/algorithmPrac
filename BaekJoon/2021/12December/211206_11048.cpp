#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> map(n, vector<int>(m));
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      dp[i][j] = map[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int f = i > 0 ? dp[i - 1][j] : 0;
      int s = j > 0 ? dp[i][j - 1] : 0;
      int t = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
      dp[i][j] += max(f, max(s, t));
    }
  }
  cout << dp[n - 1][m - 1];
  return 0;
}