#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getCount(vector<int> &dp, int curBlock)
{
  int step = dp[curBlock];
  if (step == 0)
    return 1;
  int nextArr[3] = {curBlock - 1, curBlock + 1, curBlock % 2 == 0 ? curBlock / 2 : -1};
  int count = 0;
  for (int next : nextArr)
  {
    if (next < 0 || next > 100000)
    {
      continue;
    }
    if (dp[next] == step - 1)
    {
      count += getCount(dp, next);
    }
  }
  return count;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> dp(100001, 1e9);
  dp[n] = 0;
  queue<int> que;
  que.push(n);
  int count = 0;
  while (!que.empty())
  {
    int cur = que.front();
    que.pop();
    int step = dp[cur];
    int nextArr[3] = {cur - 1, cur + 1, cur * 2};
    for (int next : nextArr)
    {
      if (next < 0 || next > 100000)
      {
        continue;
      }
      if (dp[next] >= step + 1)
      {
        dp[next] = step + 1;
        que.push(next);
      }
    }
  }
  cout << dp[k] << '\n'
       << getCount(dp, k);
  return 0;
}