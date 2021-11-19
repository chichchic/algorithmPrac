#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int>> matrix;
vector<vector<int>> dp;

int getMinCnt(int st, int ed)
{
  if (st == ed)
  {
    return 0;
  }
  if (dp[st][ed] != -1)
  {
    return dp[st][ed];
  }
  int ret = (1 << 31) - 1;
  for (int i = 0; i + st < ed; i++)
  {
    int candi = getMinCnt(st, st + i) + getMinCnt(st + i + 1, ed) + matrix[st].first * matrix[st + i].second * matrix[ed].second;
    ret = min(ret, candi);
  }
  return dp[st][ed] = ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  matrix.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> matrix[i].first >> matrix[i].second;
  }
  dp.resize(n, vector<int>(n, -1));
  cout << getMinCnt(0, n - 1);
  return 0;
}
