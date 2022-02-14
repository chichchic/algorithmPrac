#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, answer = 0;
  int seq[1000];
  int dp[1000];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }
  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (seq[i] < seq[j] && dp[j] + 1 > dp[i])
      {
        dp[i] = dp[j] + 1;
      }
    }
    answer = max(answer, dp[i]);
  }
  cout << answer;
  return 0;
}