#include <iostream>
#include <vector>

using namespace std;

int BLOCK_X[4][3] = {{0, 0, 1}, {0, 1, 1}, {0, 0, 1}, {0, 1, 1}};
int BLOCK_Y[4][3] = {{0, 1, 1}, {0, 0, 1}, {0, 1, 0}, {0, -1, 0}};
int c;

void set(vector<vector<bool>> &board, int i, int j, int dir, bool flag)
{
  for (int b = 0; b < 3; b++)
  {
    int cx = i + BLOCK_X[dir][b];
    int cy = j + BLOCK_Y[dir][b];
    board[cx][cy] = flag;
  }
}

int getFilledCase(vector<vector<bool>> &board, int emptyBlock)
{
  int i = -1, j = -1;
  for (int h = 0; h < board.size(); h++)
  {
    for (int w = 0; w < board[h].size(); w++)
    {
      if (!board[h][w])
      {
        i = h;
        j = w;
      }
      if (j != -1)
        break;
    }
    if (j != -1)
      break;
  }
  if (j == -1)
    return 1;

  int ret = 0;

  for (int dir = 0; dir < 4; dir++)
  {
    bool canFill = true;
    for (int b = 0; b < 3; b++)
    {
      int cx = i + BLOCK_X[dir][b];
      int cy = j + BLOCK_Y[dir][b];
      if (cx < 0 || cy < 0 || cx >= board.size() || cy >= board[0].size() || board[cx][cy])
      {
        canFill = false;
        break;
      }
    }
    if (canFill)
    {
      set(board, i, j, dir, true);
      ret += getFilledCase(board, emptyBlock - 3);
      set(board, i, j, dir, false);
    }
  }

  return ret;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> c;
  while (c--)
  {
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> board(h, vector<bool>(w));
    int emptyBlock = h * w;
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        char block;
        cin >> block;
        if (block == '#')
        {
          emptyBlock--;
          board[i][j] = true;
        }
      }
    }
    cout << getFilledCase(board, emptyBlock) << '\n';
  }

  return 0;
}