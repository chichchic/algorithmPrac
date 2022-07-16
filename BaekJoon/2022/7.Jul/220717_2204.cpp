#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

string lowserCase(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i] - 'A' + 'a';
    }
  }
  return str;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n)
  {
    vector<pair<string, string>> strs;
    while (n--)
    {
      string str;
      cin >> str;
      strs.push_back({lowserCase(str), str});
    }
    sort(strs.begin(), strs.end());
    cout << strs[0].second << '\n';
    cin >> n;
  }

  return 0;
}