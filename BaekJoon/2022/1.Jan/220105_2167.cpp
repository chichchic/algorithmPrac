#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> store(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> store[i][j];
    }
  }
  int k;
  cin >> k;
  while (k--)
  {
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    int ans = 0;
    for (; i <= x; i++)
    {
      for (int tempJ = j; tempJ <= y; tempJ++)
      {
        ans += store[i][tempJ];
      }
    }
    cout << ans << '\n';
  }

  return 0;
}