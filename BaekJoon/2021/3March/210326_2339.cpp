#include <iostream>

using namespace std;

int n;
int board[20][20];

bool hasJewel(int rowS, int rowE, int colS, int colE)
{
  for (int i = rowS; i <= rowE; i++)
  {
    for (int j = colS; j <= colE; j++)
    {
      if (board[i][j] == 2)
      {
        return true;
      }
    }
  }
  return false;
}

long long cutBoard(int rowS, int rowE, int colS, int colE, int prevDir)
{
  bool hasImpurity = false;
  int jewelCount = 0;
  int cuttingCase = 0;
  for (int i = rowS; i <= rowE; i++)
  {
    for (int j = colS; j <= colE; j++)
    {
      if (board[i][j] == 1)
      {
        hasImpurity = true;
        if (prevDir != 0 && !hasJewel(rowS, rowE, j, j))
        {
          // cout << rowS << rowE << colS << colE << '\n';
          // cout << j << rowS << rowE << " cut col\n";
          long long leftBoard = cutBoard(rowS, rowE, colS, j - 1, 0);
          long long rightBoard = cutBoard(rowS, rowE, j + 1, colE, 0);
          cuttingCase += leftBoard * rightBoard;
        }
        if (prevDir != 1 && !hasJewel(i, i, colS, colE))
        {
          // cout << rowS << rowE << colS << colE << '\n';
          // cout << i << colS << colE << " cut row\n";
          long long topBoard = cutBoard(rowS, i - 1, colS, colE, 1);
          long long bottomBoard = cutBoard(i + 1, rowE, colS, colE, 1);
          cuttingCase += topBoard * bottomBoard;
        }
      }
      if (board[i][j] == 2)
      {
        jewelCount++;
      }
    }
  }
  if (!hasImpurity && jewelCount == 1)
  {
    // cout << rowS << rowE << colS << colE << '\n';
    return 1;
  }
  if (jewelCount == 0)
  {
    return 0;
  }
  return cuttingCase;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }

  long long ans = cutBoard(0, n - 1, 0, n - 1, -1);
  if (ans == 0)
  {
    cout << -1;
  }
  else
  {
    cout << ans;
  }
  return 0;
}