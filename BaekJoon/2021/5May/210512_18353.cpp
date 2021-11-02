#include <iostream>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int fighting_powers[2001];
  int dp[2001];
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> fighting_powers[i];
    int max = 0;
    for (int j = 0; j < i; j++)
    {
      if (fighting_powers[j] > fighting_powers[i] && max < dp[j])
        max = dp[j];
    }
    dp[i] = max + 1;
    if (answer < dp[i])
      answer = dp[i];
  }
  cout << n - answer;
  return 0;
}