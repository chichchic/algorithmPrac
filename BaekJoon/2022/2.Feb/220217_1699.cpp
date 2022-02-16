#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(n + 1, INF);
  for (int i = 1; i * i <= n; i++)
  {
    dp[i * i] = 1;
  }
  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j * j <= i; j++)
    {
      dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
    }
  }
  cout << dp[n];

  return 0;
}