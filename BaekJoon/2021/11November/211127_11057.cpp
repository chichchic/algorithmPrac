#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 0;
const int MOD = 10007;
vector<vector<int>> dp(10, vector<int>(10001, 0));
int countUpSeqence(int cur, int len)
{
  if (len == n)
  {
    return 1;
  }
  if (dp[cur][len] != 0)
  {
    return dp[cur][len] % MOD;
  }
  for (int next = cur; next <= 9; next++)
  {
    dp[cur][len] += countUpSeqence(next, len + 1);
    dp[cur][len] % MOD;
  }
  return dp[cur][len] % MOD;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int answer = 0;
  cout << countUpSeqence(0, 0);

  return 0;
}