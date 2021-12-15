#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> coins(n);
  vector<long long> dp(k + 1, 1e5);
  for (long long i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());
  dp[0] = 0;
  for (long long i = 0; i < n; i++)
  {
    long long coin = coins[i];
    for (long long j = coin; j <= k; j++)
    {
      long long dif = j - coin;
      if (dp[dif] != 1e5)
      {
        dp[j] = min(dp[j], dp[dif] + 1);
      }
    }
  }
  cout << ((dp[k] == 1e5) ? -1 : dp[k]);
  return 0;
}