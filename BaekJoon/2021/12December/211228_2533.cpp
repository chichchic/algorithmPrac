#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> link(1000001);
vector<vector<int>> dp(1000001, vector<int>(2, -1));

int getMinCnt(int n, int status, int parent)
{
  if (dp[n][status] != -1)
  {
    return dp[n][status];
  }
  int ret = 0;
  for (int i = 0; i < link[n].size(); i++)
  {
    int child = link[n][i];
    if (child == parent)
    {
      continue;
    }
    if (status == 0)
    {
      ret += getMinCnt(child, 1, n) + 1;
    }
    else
    {
      ret += min(getMinCnt(child, 0, n), getMinCnt(child, 1, n) + 1);
    }
  }
  return dp[n][status] = ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    link[u].push_back(v);
    link[v].push_back(u);
  }
  cout << min(getMinCnt(1, 0, -1), getMinCnt(1, 1, -1) + 1);
  return 0;
}