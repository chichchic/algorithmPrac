#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
  if (a.length() == b.length())
  {
    for (int i = 0; i < a.length(); i++)
    {
      if (a[i] != b[i])
        return a < b;
    }
    return true;
  }
  return a.length() < b.length();
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<string> ans;
  while (n--)
  {
    string str;
    cin >> str;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] <= '9' && str[i] >= '0')
      {
        if (temp[0] == '0')
        {
          temp = str[i];
          continue;
        }
        temp += str[i];
      }
      else if (temp != "")
      {
        ans.push_back(temp);
        temp = "";
      }
    }
    if (temp != "")
    {
      ans.push_back(temp);
      temp = "";
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << '\n';
  return 0;
}