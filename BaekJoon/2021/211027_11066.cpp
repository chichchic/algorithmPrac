#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll dfs(vector<ll> &data, vector<vector<ll>> &dp, vector<ll> &prefix_sum, int s, int e)
{
  if (dp[s][e] != 1e17)
  {
    return dp[s][e];
  }
  if (s == e)
  {
    return 0;
  }
  if (s + 1 == e)
  {
    return dp[s][e] = data[s] + data[e];
  }
  for (int i = s; i < e; i++)
  {
    dp[s][e] = min(dp[s][e], dfs(data, dp, prefix_sum, s, i) + dfs(data, dp, prefix_sum, i + 1, e));
  }
  return dp[s][e] += prefix_sum[e] - prefix_sum[s - 1];
}

ll solution()
{
  int size;
  cin >> size;
  vector<ll> data(size + 1);
  vector<ll> prefix_sum(size + 1, 0);
  for (int i = 1; i <= size; i++)
  {
    cin >> data[i];
    prefix_sum[i] = data[i] + prefix_sum[i - 1];
  }
  vector<vector<ll>> dp(size + 1, vector<ll>(size + 1, 1e17));
  return dfs(data, dp, prefix_sum, 1, size);
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    cout << solution() << '\n';
  }

  return 0;
}