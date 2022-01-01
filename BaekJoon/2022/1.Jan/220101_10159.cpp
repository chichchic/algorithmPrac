#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
  for (int i = 0; i < m; i++)
  {
    int s, e;
    cin >> s >> e;
    cost[s][e] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
    cost[i][i] = 0;
  }
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    int ans = n;
    for (int j = 1; j <= n; j++)
    {
      if (cost[i][j] != INF || cost[j][i] != INF)
      {
        ans--;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}