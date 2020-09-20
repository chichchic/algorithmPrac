#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string first, a = "", b;
  getline(cin, first);
  getline(cin, b);

  for (int i = 0; i < first.size(); i++)
  {
    if (first[i] >= '0' && first[i] <= '9')
      continue;
    a += first[i];
  }

  vector<int> p(b.length(), 0);
  for (int i = 1, j = 0; i < b.length(); i++)
  {
    while (j > 0 && b[i] != b[j])
      j = p[j - 1];
    if (b[i] == b[j])
      p[i] = ++j;
  }

  bool ans = false;

  for (int i = 0, j = 0; i < a.length(); i++)
  {
    while (j > 0 && a[i] != b[j])
      j = p[j - 1];
    if (a[i] == b[j])
    {
      if (j == b.length() - 1)
      {
        ans = true;
        break;
      }
      else
        j++;
    }
    if (ans)
      break;
  }
  if (!ans)
    cout << 0;
  else
    cout << 1;

  return 0;
}