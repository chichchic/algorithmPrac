#include <iostream>
#include <string>

using namespace std;

int n;
bool findAns = false;

bool hasPattern(string str)
{
  int len = str.length();
  for (int i = 1; i <= len / 2; i++)
  {
    int j = len - 1;
    int k = j - i;
    bool pattern = true;
    int depth = 0;
    while (depth < i)
    {
      if (str[j--] != str[k--])
      {
        pattern = false;
        break;
      }
      depth++;
    }
    if (pattern)
    {
      return true;
    }
  }
  return false;
}

void backTracking(int depth, string str)
{
  if (hasPattern(str) || findAns)
    return;
  if (depth == n)
  {
    findAns = true;
    cout << str;
  }
  backTracking(depth + 1, str + '1');
  backTracking(depth + 1, str + '2');
  backTracking(depth + 1, str + '3');
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  backTracking(0, "");
  return 0;
}