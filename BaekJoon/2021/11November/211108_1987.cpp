#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int r, c;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  vector<vector<char>> board(r, vector<char>(c));
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> board[i][j];
    }
  }
  queue<pair<pair<int, int>, int>> que;
  int initStatus = 0 | (1 << board[0][0] - 'A');
  que.push({{0, 0}, initStatus});
  que.push({{-1, 0}, initStatus});
  int answer = 0;
  while (!que.empty())
  {
    int curX = que.front().first.first;
    int curY = que.front().first.second;
    int curStatus = que.front().second;
    que.pop();
    if (curX == -1)
    {
      answer++;
      que.push({{-1, 0}, initStatus});
      if (que.size() == 1)
      {
        break;
      }
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int nextX = curX + mx[i];
      int nextY = curY + my[i];
      if (nextX < 0 || nextY < 0 || nextX >= r || nextY >= c || curStatus & (1 << (board[nextX][nextY] - 'A')))
      {
        continue;
      }
      que.push({{nextX, nextY}, curStatus | (1 << (board[nextX][nextY] - 'A'))});
    }
  }
  cout << answer;
  return 0;
}