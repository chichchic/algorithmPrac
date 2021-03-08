#include <iostream>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string str1, str2;
  cin >> str1 >> str2;
  str1 = '0' + str1;
  str2 = '0' + str2;

  int len1 = str1.size();
  int len2 = str2.size();

  int lcs[1001][1001];

  for (int i = 0; i < len1; i++)
  {
    for (int j = 0; j < len2; j++)
    {
      if (i == 0 || j == 0)
      {
        lcs[i][j] = 0;
        continue;
      }

      if (str1[i] == str2[j])
      {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      }
      else
      {
        lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
      }
    }
  }

  int lcsLen = lcs[len1 - 1][len2 - 1];
  cout << lcsLen << '\n';
  if (lcsLen == 0)
  {
    return 0;
  }

  int i = len1 - 1;
  int j = len2 - 1;
  string ans = "";
  while (i >= 0 && j >= 0)
  {
    if (lcs[i][j] == lcs[i][j - 1])
    {
      j--;
    }
    else if (lcs[i][j] == lcs[i - 1][j])
    {
      i--;
    }
    else
    {
      ans = str2[j] + ans;
      i--;
      j--;
    }
  }
  cout << ans;
  return 0;
}