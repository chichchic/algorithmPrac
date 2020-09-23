#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string p, s;
  getline(cin, s);
  getline(cin, p);

  vector<int> part(p.length(), 0);

  for (int i = 1, j = 0; i < p.length(); i++)
  {
    while (j > 0 && p[i] != p[j])
      j = part[j - 1];
    if (p[i] == p[j])
      part[i] = ++j;
  }

  bool ans = false;

  for (int i = 0, j = 0; i < s.length(); i++)
  {
    while (j > 0 && s[i] != p[j])
      j = part[j - 1];
    if (s[i] == p[j])
    {

      if (p.length() - 1 == j)
      {
        ans = true;
        break;
      }
      else
        j++;
    }
  }
  if (!ans)
    cout << 0;
  else
    cout << 1;

  return 0;
}