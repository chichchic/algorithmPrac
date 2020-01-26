#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n != 0)
  {
    vector<long long> h(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> h[i];
      if (ans < h[i])
        ans = h[i];
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < n - i; j++)
      {
        if (h[j] > h[j + i])
          h[j] = h[j + i];
        if (h[j] * (i + 1) > ans)
          ans = h[j] * (i + 1);
      }
    }

    cin >> n;
  }
}