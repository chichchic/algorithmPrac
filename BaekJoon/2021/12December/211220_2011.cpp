#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input;
  cin >> input;
  if (input[0] == '0')
  {
    cout << 0;
    return 0;
  }
  vector<int> dp(input.size() + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= input.size(); i++)
  {
    if (input[i - 1] >= '1' && input[i - 1] <= '9')
    {
      dp[i] = (dp[i - 1] + dp[i]) % 1000000;
    }
    if (i == 1)
    {
      continue;
    }
    if (input[i - 2] == '1' || (input[i - 2] == '2' && input[i - 1] <= '6'))
    {
      dp[i] = (dp[i - 2] + dp[i]) % 1000000;
    }
  }
  cout << dp[input.size()];
  return 0;
}