#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;
  int min = -1;
  int total = 0;
  for (int i = m; i <= n; i++)
  {
    for (int j = 1; j * j <= i; j++)
    {
      if (j * j == i)
      {
        if (min == -1)
        {
          min = i;
        }
        total += i;
      }
    }
  }
  if (min == -1)
  {
    cout << -1;
  }
  else
  {
    cout << total << '\n'
         << min;
  }
  return 0;
}