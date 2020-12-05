#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pii> dp(n + 1, make_pair(n + 1, 0));
  dp[1] = make_pair(0, 0);
  for (int i = 1; i <= n; i++)
  {
    int cnt = dp[i].first + 1;
    if (i + 1 <= n && dp[i + 1].first > cnt)
    {
      dp[i + 1] = make_pair(cnt, i);
    }
    if (i * 2 <= n && dp[i * 2].first > cnt)
    {
      dp[i * 2] = make_pair(cnt, i);
    }
    if (i * 3 <= n && dp[i * 3].first > cnt)
    {
      dp[i * 3] = make_pair(cnt, i);
    }
  }

  int target = n;
  cout << dp[target].first << '\n';
  cout << target << ' ';
  while (target != 1)
  {
    target = dp[target].second;
    cout << target << ' ';
  }

  return 0;
}