#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 1)
  {
    cout << 0;
    return 0;
  }
  vector<long long> dp(n + 1);
  dp[0] = 1;
  dp[2] = 3;
  for (int i = 4; i <= n; i += 2)
  {
    dp[i] = dp[i - 2] * 3;
    for (int j = 4; j < i; j += 2)
    {
      dp[i] += dp[i - j] * 2;
    }
    dp[i] += 2;
  }
  cout << dp[n];
  return 0;
}