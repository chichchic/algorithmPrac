#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  vvi busCost(n + 1, vi(n + 1, 1e8));

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    busCost[a][b] = min(busCost[a][b], c);
  }
  for (int i = 1; i <= n; i++)
    busCost[i][i] = 0;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        busCost[i][j] = min(busCost[i][j], busCost[i][k] + busCost[k][j]);

  for (int i = 1; i <= n; i++,
           printf("\n"))
    for (int j = 1; j <= n; j++)
      printf("%d ", busCost[i][j] == 1e8 ? 0 : busCost[i][j]);
  return 0;
}