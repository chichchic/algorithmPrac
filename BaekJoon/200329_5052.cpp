#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++)
    {
      cin >> input[i];
    }
    sort(input.begin(), input.end());
    bool yes;
    for (int i = 0; i < n - 1; i++)
    {
      int slen = (input[i].length() < input[i + 1].length()) ? input[i].length() : input[i + 1].length();
      yes = false;
      for (int j = 0; j < slen; j++)
      {
        if (input[i][j] != input[i + 1][j])
        {
          yes = true;
          break;
        }
      }
      if (!yes)
        break;
    }
    if (yes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}