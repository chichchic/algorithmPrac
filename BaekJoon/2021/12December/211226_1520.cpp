#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int m, n;
vector<vector<int>> map(500, vector<int>(500));
vector<vector<int>> visited(500, vector<int>(500, -1));
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int getCase(int x, int y)
{
  if (visited[x][y] != -1)
  {
    return visited[x][y];
  }
  int ret = 0;
  for (int i = 0; i < 4; i++)
  {
    int nextx = x + mx[i];
    int nexty = y + my[i];
    if (nextx < 0 || nextx >= m || nexty < 0 || nexty > n || map[x][y] <= map[nextx][nexty])
    {
      continue;
    }
    ret += getCase(nextx, nexty);
  }
  return visited[x][y] = ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }
  visited[m - 1][n - 1] = 1;
  cout << getCase(0, 0);
  return 0;
}