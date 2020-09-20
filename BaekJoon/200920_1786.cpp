#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  getline(cin, a);
  getline(cin, b);

  vector<int> p(b.length(), 0);

  for (int i = 1, j = 0; i < b.length(); i++)
  {
    while (j > 0 && b[i] != b[j])
      j = p[j - 1];
    if (b[i] == b[j])
      p[i] = ++j;
  }

  vector<int> ans;

  for (int i = 0, j = 0; i < a.length(); i++)
  {
    while (j > 0 && a[i] != b[j])
      j = p[j - 1];
    if (a[i] == b[j])
    {
      if (j == b.length() - 1)
      {
        ans.push_back(i - j + 1);
        j = p[j];
      }
      else
        j++;
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << '\n';
  }

  return 0;
}