#include <iostream>
#include <vector>

using namespace std;

int board[11][11];
int answer1 = 0;
int answer2 = 0;
void setBishopBlack(vector<bool> &locatedRL, vector<bool> &locatedLR, int x, int y, int cnt, const int n)
{
  if (x >= n)
  {
    return;
  }
  answer1 = max(answer1, cnt);
  int j = y;
  for (int i = x; i < n; i++)
  {
    for (; j < n; j += 2)
    {
      if (!locatedRL[i + j] && !locatedLR[i - j + n] && board[i][j] == 1)
      {
        locatedRL[i + j] = true;
        locatedLR[i - j + n] = true;
        board[i][j] = 0;
        setBishopBlack(locatedRL, locatedLR, i, j + 2, cnt + 1, n);
        locatedRL[i + j] = false;
        locatedLR[i - j + n] = false;
        board[i][j] = 1;
      }
    }
    if (i % 2 == 0)
    {
      j = 0;
    }
    else
    {
      j = 1;
    }
  }
}
void setBishopWhite(vector<bool> &locatedRL, vector<bool> &locatedLR, int x, int y, int cnt, const int n)
{
  answer2 = max(answer2, cnt);
  int j = y;
  for (int i = x; i < n; i++)
  {
    for (; j < n; j += 2)
    {
      if (!locatedRL[i + j] && !locatedLR[i - j + n] && board[i][j] == 1)
      {
        locatedRL[i + j] = true;
        locatedLR[i - j + n] = true;
        board[i][j] = 0;
        setBishopWhite(locatedRL, locatedLR, i, j + 2, cnt + 1, n);
        locatedRL[i + j] = false;
        locatedLR[i - j + n] = false;
        board[i][j] = 1;
      }
    }
    if (i % 2 == 0)
    {
      j = 1;
    }
    else
    {
      j = 0;
    }
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int maxAnswer = n * 2 - 1;
  vector<bool> loactedRL(n * 2 + 1, false);
  vector<bool> loactedLR(n * 2 + 1, false);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  setBishopBlack(loactedRL, loactedLR, 0, 1, 0, n);
  setBishopWhite(loactedRL, loactedLR, 0, 0, 0, n);
  cout << answer1 + answer2;

  return 0;
}