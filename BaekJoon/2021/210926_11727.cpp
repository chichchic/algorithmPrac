#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;
int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> dp(1001);
  dp[1] = 1;
  dp[2] = 3;
  int target;
  cin >> target;
  for (int i = 3; i <= target; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
  }
  cout << dp[target] % MOD;
  return 0;
}