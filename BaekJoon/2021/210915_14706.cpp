#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 200000000000001LL);
  vector<pair<long long, long long>> rule;
  for (long long i = 0; i < m; i++)
  {
    long long l, s;
    cin >> l >> s;
    rule.push_back(make_pair(l, s));
  }
  for (long long i = 1; i <= n; ++i)
  {
    for (long long j = 0; j < m; j++)
    {
      long long l = rule[j].first;
      long long s = rule[j].second;
      dp[i] = min(dp[i], (i - l <= 0 ? 0 : dp[i - l]) + s);
    }
    cout << dp[i] << '\n';
  }
  return 0;
}