#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
bool tiltBoard(vector<vector<char>> &board, int moveIdx, pair<int, int> &bB, pair<int, int> &rB, int depth)
{
  // cout << depth << ' ' << moveIdx << ' ' << rB.first << ' ' << rB.second << ' ' << bB.first << ' ' << bB.second << " :::init\n";
  if (depth > 10)
  {
    return false;
  }
  int xd = mx[moveIdx], yd = my[moveIdx];
  bool isMoved = true;
  bool redDrop = false;
  bool moveOnce = false;

  while (isMoved)
  {
    isMoved = false;
    if (board[bB.first + xd][bB.second + yd] == '.')
    {
      board[bB.first + xd][bB.second + yd] = 'B';
      board[bB.first][bB.second] = '.';
      bB.first += xd;
      bB.second += yd;
      isMoved = true;
      moveOnce = true;
    }
    else if (board[bB.first + xd][bB.second + yd] == 'O')
    {
      return false;
    }
    if (board[rB.first + xd][rB.second + yd] == '.')
    {
      board[rB.first + xd][rB.second + yd] = 'R';
      board[rB.first][rB.second] = '.';
      rB.first += xd;
      rB.second += yd;
      isMoved = true;
      moveOnce = true;
    }
    else if (!redDrop && board[rB.first + xd][rB.second + yd] == 'O')
    {
      board[rB.first][rB.second] = '.';
      redDrop = true;
      isMoved = true;
      moveOnce = true;
    }
  }
  if (!moveOnce)
  {
    return false;
  }
  if (redDrop)
  {
    return true;
  }
  pair<int, int> ibB = bB, irB = rB;
  for (int i = 0; i < 4; i++)
  {
    // cout << depth << ' ' << i << ' ' << rB.first << ' ' << rB.second << ' ' << bB.first << ' ' << bB.second << " :::\n";
    if (i == moveIdx)
    {
      continue;
    }
    if (tiltBoard(board, i, bB, rB, depth + 1))
    {
      return true;
    }
    board[bB.first][bB.second] = '.';
    board[rB.first][rB.second] = '.';
    board[ibB.first][ibB.second] = 'B';
    board[irB.first][irB.second] = 'R';
    bB = ibB;
    rB = irB;
  }
  return false;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> board(n, vector<char>(m));
  pair<int, int> bB, rB;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 'B')
      {
        bB = {i, j};
      }
      if (board[i][j] == 'R')
      {
        rB = {i, j};
      }
    }
  }
  pair<int, int> ibB = bB, irB = rB;
  for (int i = 0; i < 4; i++)
  {
    if (tiltBoard(board, i, bB, rB, 1))
    {
      cout << 1;
      return 0;
    }
    board[bB.first][bB.second] = '.';
    board[rB.first][rB.second] = '.';
    board[ibB.first][ibB.second] = 'B';
    board[irB.first][irB.second] = 'R';
    bB = ibB;
    rB = irB;
  }
  cout << 0;
  return 0;
}