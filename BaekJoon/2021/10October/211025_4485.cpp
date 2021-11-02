#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int n)
{
  vector<vector<int>> cave(n, vector<int>(n));
  vector<vector<int>> lossValue(n, vector<int>(n, 9999999));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> cave[i][j];
    }
  }
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};

  priority_queue<pair<int, pair<int, int>>> que;
  que.push({-cave[0][0], {0, 0}});
  lossValue[0][0] = cave[0][0];
  while (!que.empty())
  {
    int curX = que.top().second.first;
    int curY = que.top().second.second;
    int curLoss = -que.top().first;
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int nextX = curX + mx[i];
      int nextY = curY + my[i];
      if (nextX >= n || nextX < 0 || nextY >= n || nextY < 0)
      {
        continue;
      }
      int nextLoss = curLoss + cave[nextX][nextY];
      if (nextLoss >= lossValue[nextX][nextY])
      {
        continue;
      }
      lossValue[nextX][nextY] = nextLoss;
      que.push({-nextLoss, {nextX, nextY}});
    }
  }
  return lossValue[n - 1][n - 1];
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int cnt = 1;
  while (true)
  {
    cin >> n;
    if (n == 0)
      return 0;
    cout << "Problem " << cnt++ << ": " << solution(n) << '\n';
  }
  return 0;
}