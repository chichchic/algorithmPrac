#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, s;
  cin >> n >> k;
  vector<vector<int>> incidence(n + 1);
  vector<vector<int>> distance(n + 1, vector<int>(n + 1, 1e9));

  for (int i = 0; i < k; i++)
  {
    int a, b;
    cin >> a >> b;
    distance[a][b] = 1;
  }

  for (int i = 1; i <= n; i++)
  {
    distance[i][i] = 0;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  }

  cin >> s;
  for (int i = 0; i < s; i++)
  {
    int a, b;
    cin >> a >> b;
    if (distance[a][b] != 1e9)
    {
      cout << -1 << '\n';
    }
    else if (distance[b][a] != 1e9)
    {
      cout << 1 << '\n';
    }
    else
    {
      cout << 0 << '\n';
    }
  }
  return 0;
}