#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int mr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int mc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void setBoard(char board[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> board[i][j];
    }
  }
}

void setNextFlag(char board[5][5], int nextFlag[5][5][26][9])
{
  for (int r = 0; r < 5; r++)
  {
    for (int c = 0; c < 5; c++)
    {
      for (int i = 0; i < 8; i++)
      {
        int nr = r + mr[i];
        int nc = c + mc[i];
        if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)
        {
          continue;
        }
        int alpha = board[nr][nc];
        nextFlag[r][c][alpha - 'A'][nextFlag[r][c][alpha - 'A'][0] + 1] = i;
        nextFlag[r][c][alpha - 'A'][0]++;
      }
    }
  }
}

bool existNext(char *trg, int cursor, int r, int c, int nextFlag[5][5][26][9])
{
  if (strlen(trg) == cursor)
  {
    return true;
  }
  if (nextFlag[r][c][trg[cursor] - 'A'][0] == 0)
  {
    return false;
  }
  for (int i = 1; i <= nextFlag[r][c][trg[cursor] - 'A'][0]; i++)
  {
    int dir = nextFlag[r][c][trg[cursor] - 'A'][i];
    if (existNext(trg, cursor + 1, r + mr[dir], c + mc[dir], nextFlag))
    {
      return true;
    }
  }
  return false;
}

bool existWord(char *trg, char board[5][5], int nextFlag[5][5][26][9])
{
  for (int r = 0; r < 5; r++)
  {
    for (int c = 0; c < 5; c++)
    {
      if (trg[0] != board[r][c])
      {
        continue;
      }
      if (existNext(trg, 1, r, c, nextFlag))
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    char board[5][5];
    setBoard(board);
    int nextFlag[5][5][26][9] = {};
    setNextFlag(board, nextFlag);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      char trg[11];
      cin >> trg;
      cout << trg;
      if (existWord(trg, board, nextFlag))
      {
        cout << " YES\n";
      }
      else
      {
        cout << " NO\n";
      }
    }
  }

  return 0;
}