#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
const int INF = 1e7;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  int input[1001][1001];
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  cin >> n >> m >> k;
  if (n == 1 && m == 1)
  {
    cout << 1;
    return 0;
  }
  vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
  queue<pair<pair<int, int>, int>> que;
  que.push({{0, 0}, 0});
  que.push({{0, 0}, -1});
  dp[0][0][0] = true;
  for (int i = 0; i < n; i++)
  {
    string in;
    cin >> in;
    for (int j = 0; j < m; j++)
    {
      input[i][j] = in[j] - '0';
    }
  }
  int ans = 1;
  while (!que.empty())
  {
    int curx = que.front().first.first;
    int cury = que.front().first.second;
    int energy = que.front().second;
    que.pop();
    if (energy == -1)
    {
      ans++;
      if (que.empty())
      {
        break;
      }
      que.push({{0, 0}, -1});
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int nextx = curx + mx[i];
      int nexty = cury + my[i];
      if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
      {
        continue;
      }
      if (nextx == n - 1 && nexty == m - 1)
      {
        cout << ans + 1;
        return 0;
      }
      if (input[nextx][nexty] == 1)
      {
        if (energy >= k || dp[nextx][nexty][energy + 1])
        {
          continue;
        }
        dp[nextx][nexty][energy + 1] = true;
        que.push({{nextx, nexty}, energy + 1});
      }
      else if (!dp[nextx][nexty][energy])
      {
        dp[nextx][nexty][energy] = true;
        que.push({{nextx, nexty}, energy});
      }
    }
  }
  cout << -1;
  return 0;
}