#include <iostream>
#include <string>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int m, n, k;
  string str;
  cin >> m >> n >> k;
  for (int i = 0; i < m; i++)
  {
    cin >> str;
    string output = "", temp = "";
    temp += str[0];
    for (int j = 1; j < n; j++)
    {
      if (str[j] != str[j - 1])
      {
        for (int l = 0; l < k; l++)
        {
          output += temp;
        }
        temp = "";
      }
      temp += str[j];
    }
    for (int l = 0; l < k; l++)
    {
      output += temp;
    }
    for (int l = 0; l < k; l++)
    {
      cout << output << '\n';
    }
  }
  return 0;
}