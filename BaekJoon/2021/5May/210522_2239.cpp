#include <iostream>

using namespace std;

bool row[9][10];
bool col[9][10];
bool box[9][10];
int matrix[9][9];
bool solved = false;

void dfs(int r, int c)
{
  if (solved)
  {
    return;
  }
  if (r == 9 && c == 0)
  {
    solved = true;
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        cout << matrix[i][j];
      }
      cout << '\n';
    }
  }
  if (matrix[r][c])
  {
    if (c + 1 >= 9)
    {
      dfs(r + 1, 0);
    }
    else
    {
      dfs(r, c + 1);
    }
    return;
  }
  for (int i = 1; i <= 9; ++i)
  {
    if (!row[r][i] && !col[c][i] && !box[r / 3 * 3 + c / 3][i])
    {
      row[r][i] = true;
      col[c][i] = true;
      box[r / 3 * 3 + c / 3][i] = true;
      matrix[r][c] = i;
      if (c + 1 >= 9)
      {
        dfs(r + 1, 0);
      }
      else
      {
        dfs(r, c + 1);
      }
      matrix[r][c] = 0;
      row[r][i] = false;
      col[c][i] = false;
      box[r / 3 * 3 + c / 3][i] = false;
    }
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; ++j)
    {
      int number;
      scanf("%1d", &number);
      row[i][number] = number;
      col[j][number] = number;
      box[i / 3 * 3 + j / 3][number] = number;
      matrix[i][j] = number;
    }
  }

  dfs(0, 0);

  return 0;
}