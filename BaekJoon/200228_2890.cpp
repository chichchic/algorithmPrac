#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int r, c;
  cin >> r >> c;
  vector<string> satelite(r);
  vector<bool> check(r, false);
  int ans[9];
  for (int i = 0; i < r; i++)
  {
    cin >> satelite[i];
  }
  int rank = 1;
  for (int i = c - 2; i > 0; i--)
  {
    bool findR = false;
    for (int j = 0; j < r; j++)
    {
      if (!check[j] && satelite[j][i] != '.')
      {
        int number = satelite[j][i] - '0';
        findR = true;
        check[j] = true;
        ans[number - 1] = rank;
      }
    }
    if (findR)
      rank++;
  }
  for (int i = 0; i < 9; i++)
  {
    cout << ans[i] << '\n';
  }
  return 0;
}