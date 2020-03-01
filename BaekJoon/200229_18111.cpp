#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, m, b, ans1 = 9223372036854775807, ans2 = 0;
  long long foundation[257] = {};

  cin >> n >> m >> b;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int temp;
      cin >> temp;
      foundation[temp]++;
    }
  }

  for (int mid = 0; mid < 257; mid++)
  {
    long long item = b;
    long long time = 0;
    for (int i = 0; i < 257; i++)
    {
      if (i < mid)
      {
        long long used = (mid - i) * foundation[i];
        time += used;
        item -= used;
      }
      else if (i > mid)
      {
        long long diged = (i - mid) * foundation[i];
        time += diged * 2;
        item += diged;
      }
    }
    if (item >= 0)
    {
      if (ans1 > time)
      {
        ans1 = time;
        ans2 = mid;
      }
      else if (ans1 == time)
      {
        if (ans2 < mid)
          ans2 = mid;
      }
    }
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}