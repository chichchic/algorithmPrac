#include <iostream>
#include <algorithm>

using namespace std;

int findLCS(string a, string b, string c)
{
  int table[101][101][101] = {};
  int a_len = a.length();
  int b_len = b.length();
  int c_len = c.length();
  for (int i = 0; i < a_len; i++)
  {
    for (int j = 0; j < b_len; j++)
    {
      for (int k = 0; k < c_len; k++)
      {

        if (a[i] == b[j] && b[j] == c[k])
        {
          table[i + 1][j + 1][k + 1] = table[i][j][k] + 1;
        }
        else
        {
          table[i + 1][j + 1][k + 1] = max(table[i][j + 1][k + 1], max(table[i + 1][j][k + 1], table[i + 1][j + 1][k]));
        }
      }
    }
  }
  return table[a_len][b_len][c_len];
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  cout << findLCS(a, b, c);
  return 0;
}