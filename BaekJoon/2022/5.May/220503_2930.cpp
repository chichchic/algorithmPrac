#include <iostream>
#include <vector>

using namespace std;

int fight(char a, char b)
{
  if (a == b)
  {
    return 1;
  }
  if (a == 'R')
  {
    if (b == 'S')
    {
      return 2;
    }
    else
    {
      return 0;
    }
  }
  if (a == 'P')
  {
    if (b == 'S')
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else if (a == 'S')
  {
    if (b == 'P')
    {
      return 2;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r;
  cin >> r;
  vector<char> sang(r);
  for (int i = 0; i < r; i++)
  {
    cin >> sang[i];
  }
  int n;
  cin >> n;
  int realScore = 0;
  vector<vector<char>> friends(n, vector<char>(r));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < r; j++)
    {
      cin >> friends[i][j];
      realScore += fight(sang[j], friends[i][j]);
    }
  }
  cout << realScore << '\n';
  int maxScore = 0;
  for (int j = 0; j < r; j++)
  {
    int r = 0, p = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
      r += fight('R', friends[i][j]);
      p += fight('P', friends[i][j]);
      s += fight('S', friends[i][j]);
    }
    maxScore += max(r, max(p, s));
  }
  cout << maxScore;

  return 0;
}