#include <iostream>
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

bool hasCharacter(int r, int c, int cursor, char *trg, char (*board)[5], bool (*cache)[5][10])
{
  if (cursor == strlen(trg))
  {
    return true;
  }

  if (cache[r][c][cursor])
  {
    return false;
  }

  for (int i = 0; i < 8; i++)
  {
    int nr = mr[i] + r;
    int nc = mc[i] + c;
    if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)
      continue;
    if (trg[cursor] == board[nr][nc] && hasCharacter(nr, nc, cursor + 1, trg, board, cache))
    {
      return true;
    }
  }
  cache[r][c][cursor] = true;
  return false;
}

bool hasString(char *trg, char (*board)[5])
{
  int len = strlen(trg);
  bool cache[5][5][10] = {};

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (board[i][j] != trg[0])
        continue;
      if (hasCharacter(i, j, 1, trg, board, cache))
        return true;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      char trg[11];
      cin >> trg;
      cout << trg;

      if (hasString(trg, board))
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