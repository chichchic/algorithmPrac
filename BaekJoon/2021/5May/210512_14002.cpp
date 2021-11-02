#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int a[1001] = {9999};
  pair<int, int> dp[1001];
  dp[0] = {0, 0};
  vector<int> answer;
  int tail = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    dp[i] = {1, 0};
    for (int j = 1; j < i; j++)
    {
      if (a[i] > a[j] && dp[i].first <= dp[j].first)
      {
        dp[i] = {dp[j].first + 1, j};
      }
    }
    if (dp[tail].first < dp[i].first)
    {
      tail = i;
    }
  }
  cout << dp[tail].first << '\n';
  while (tail != 0)
  {
    answer.push_back(a[tail]);
    tail = dp[tail].second;
  }
  while (!answer.empty())
  {
    cout << answer.back() << ' ';
    answer.pop_back();
  }

  return 0;
}