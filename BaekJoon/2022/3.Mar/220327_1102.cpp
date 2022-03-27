#include <iostream>
#include <vector>

using namespace std;
int n, p;
vector<vector<int>> costs(16, vector<int>(16, 0));
vector<int> dp(1 << 16, 1e9);
int answer = 1e9;
void findMin(int status, int runCnt)
{
  if (runCnt >= p)
  {
    answer = min(answer, dp[status]);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if ((status & (1 << i)) == 0)
    {
      int minCost = 1e9;
      int nextStatus = (status | (1 << i));
      for (int j = 0; j < n; j++)
      {
        if (j == n - i - 1 || (status & (1 << (n - j - 1))) == 0)
        {
          continue;
        }
        minCost = min(minCost, costs[j][n - i - 1]);
        // cout << j << ' ' << n - i - 1 << ' ' << costs[j][n - i - 1] << endl;
      }
      if (dp[nextStatus] > dp[status] + minCost)
      {
        dp[nextStatus] = dp[status] + minCost;
        // cout << nextStatus << ' ' << dp[nextStatus] << endl;
        findMin(nextStatus, runCnt + 1);
      }
    }
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> costs[i][j];
    }
  }
  string status;
  cin >> status;
  cin >> p;
  int currentStatus = 0;
  int runCnt = 0;
  for (int i = 0; i < status.length(); i++)
  {
    if (status[status.length() - i - 1] == 'Y')
    {
      currentStatus |= 1 << i;
      runCnt++;
    }
  }
  if (p == 0)
  {
    cout << 0;
    return 0;
  }
  if (runCnt == 0)
  {
    cout << -1;
    return 0;
  }
  dp[currentStatus] = 0;
  findMin(currentStatus, runCnt);
  cout << answer;
  return 0;
}