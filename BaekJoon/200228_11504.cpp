#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long testCase, n, m, x, y;
  long long temp;
  cin >> testCase;
  while (testCase--)
  {
    cin >> n >> m >> x;
    long long ans = 0;
    vector<long long> wheel(n);
    for (long long i = 1; i < m; i++)
    {
      x *= 10;
      cin >> temp;
      x += temp;
    }
    cin >> y;
    for (long long i = 1; i < m; i++)
    {
      y *= 10;
      cin >> temp;
      y += temp;
    }
    for (long long i = 0; i < n; i++)
      cin >> wheel[i];
    for (long long i = 0; i < n; i++)
    {
      long long z = 0;
      for (long long j = 0; j < m; j++)
      {
        z *= 10;
        z += wheel[(i + j) % n];
      }
      if (z >= x && z <= y)
        ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}