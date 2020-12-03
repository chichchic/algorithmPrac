#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (true)
  {
    string str;
    int order;
    cin >> str;
    if (cin.eof())
      break;
    cin >> order;
    int maxOrder = 1;
    int len = str.length();
    for (int i = 2; i <= len; i++)
    {
      maxOrder *= i;
    }
    if (order > maxOrder)
    {
      cout << str << ' ' << order << " = No permutation\n";
      continue;
    }
    vector<int> change(len, 0);
    int unit = maxOrder;
    int originOrder = order;
    for (int i = 0; i < len - 2; i++)
    {
      unit /= len - i;
      change[i] = (order - 1) / unit;
      order -= unit * change[i];
    }
    if (order == 2)
    {
      change[len - 2] = 1;
    }
    else
    {
      change[len - 2] = 0;
    }
    change[len - 1] = 0;

    vector<bool> isUsed(len, false);
    string result = "";
    vector<char> stack;
    for (int i = len - 1; i >= 0; i--)
    {
      stack.push_back(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
      vector<char> temp;
      int j = 0;
      while (j++ < change[i])
      {
        char tempChar = stack.back();
        stack.pop_back();
        temp.push_back(tempChar);
      }
      char target = stack.back();
      stack.pop_back();
      result += target;
      while (!temp.empty())
      {
        char tempChar = temp.back();
        temp.pop_back();
        stack.push_back(tempChar);
      }
    }
    cout << str << ' ' << originOrder << " = " << result << '\n';
  }

  return 0;
}