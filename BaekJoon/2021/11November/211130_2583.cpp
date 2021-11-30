#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  vector<vector<bool>> board(m, vector<bool>(n, false));
  vector<vector<bool>> checked(m, vector<bool>(n, false));
  while (k--)
  {
    int sx, sy, ex, ey;
    cin >> sy >> sx >> ey >> ex;
    for (; sx < ex; sx++)
    {
      for (int j = sy; j < ey; j++)
      {
        board[sx][j] = true;
      }
    }
  }
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  vector<int> answerArr;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (checked[i][j] || board[i][j])
      {
        continue;
      }
      int answer = 0;
      queue<pair<int, int>> que;
      que.push({i, j});
      checked[i][j] = true;
      while (!que.empty())
      {
        int curx = que.front().first;
        int cury = que.front().second;
        que.pop();
        answer++;
        for (int i = 0; i < 4; i++)
        {
          int nextx = curx + mx[i];
          int nexty = cury + my[i];
          if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n || checked[nextx][nexty] || board[nextx][nexty])
          {
            continue;
          }
          checked[nextx][nexty] = true;
          que.push({nextx, nexty});
        }
      }
      answerArr.push_back(answer);
    }
  }
  cout << answerArr.size() << '\n';
  sort(answerArr.begin(), answerArr.end());
  for (auto a : answerArr)
  {
    cout << a << ' ';
  }
  return 0;
}