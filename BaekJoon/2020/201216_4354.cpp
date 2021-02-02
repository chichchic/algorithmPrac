#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hasPattern(const string &str)
{
  int depth = 1;
  int len = str.length();
  vector<int> fail(len, 0);
  int j = 0;
  for (int i = 1; i < len; i++)
  {
    while (j > 0 && str[i] != str[j])
    {
      j = fail[j - 1];
    }
    if (str[i] == str[j])
    {
      fail[i] = ++j;
    }
  }
  int interval = len - j;
  if (j * 2 < len)
    return 1;
  else if (j % interval == 0)
    return j / interval + 1;
  else
    return 1;
  // if (j * 2 > len)
  //   return hasPattern(str.substr(len - j), depth + 1);
  // else if (j * 2 == len)
  //   return depth + 1;
  // else
  //   return 1;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (true)
  {
    string str;
    cin >> str;
    if (str == ".")
      break;
    cout << hasPattern(str) << '\n';
  }

  return 0;
}