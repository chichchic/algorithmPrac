#include <iostream>
#include <vector>

using namespace std;

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int n;
vector<vector<int>> dp;
int getMaxMove(int x, int y, vector<vector<int>> &bambooes, vector<vector<bool>> &visited)
{
  if (dp[x][y] != -1)
  {
    return dp[x][y];
  }
  int cnt = 1;
  for (int i = 0; i < 4; i++)
  {
    int nextX = x + mx[i];
    int nextY = y + my[i];
    if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n || visited[nextX][nextY] || bambooes[nextX][nextY] <= bambooes[x][y])
      continue;
    visited[nextX][nextY] = true;
    cnt = max(cnt, getMaxMove(nextX, nextY, bambooes, visited) + 1);
    visited[nextX][nextY] = false;
  }
  dp[x][y] = cnt;
  return cnt;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<vector<int>> bambooes(n, vector<int>(n));
  dp.resize(n, vector<int>(n, -1));
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> bambooes[i][j];
    }
  }
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      answer = max(answer, getMaxMove(i, j, bambooes, visited));
    }
  }
  // for (auto line : dp)
  // {
  //   for (auto data : line)
  //   {
  //     cout << data << ' ';
  //   }
  //   cout << '\n';
  // }
  cout << answer;
  return 0;
}