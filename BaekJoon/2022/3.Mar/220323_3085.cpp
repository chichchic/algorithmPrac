#include <iostream>
#include <vector>

using namespace std;

int maxlen(vector<vector<char>> &board, int x, int y)
{
  int xlen = 1;
  int ylen = 1;
  for (int i = x; i < board.size() - 1; i++)
  {
    if (board[i][y] != board[i + 1][y])
    {
      break;
    }
    xlen++;
  }
  for (int i = y; i < board.size() - 1; i++)
  {
    if (board[x][i] != board[x][i + 1])
    {
      break;
    }
    ylen++;
  }
  return max(xlen, ylen);
}
int check(vector<vector<char>> &board)
{
  int ret = 0;
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board.size(); j++)
    {
      ret = max(ret, maxlen(board, i, j));
    }
  }
  return ret;
}

void swap(vector<vector<char>> &board, int x1, int y1, int x2, int y2)
{
  char temp = board[x1][y1];
  board[x1][y1] = board[x2][y2];
  board[x2][y2] = temp;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<char>> board(n, vector<char>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (j + 1 < n)
      {
        swap(board, i, j, i, j + 1);
        answer = max(answer, check(board));
        swap(board, i, j, i, j + 1);
      }
      if (i + 1 < n)
      {
        swap(board, i, j, i + 1, j);
        answer = max(answer, check(board));
        swap(board, i, j, i + 1, j);
      }
    }
  }
  cout << answer;

  return 0;
}