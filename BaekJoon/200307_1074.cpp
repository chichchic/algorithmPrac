#include <iostream>
#include <cmath>

using namespace std;

long long ans = 0;

void z(long long n, long long r, long long c)
{
  if (n == 1)
  {
    if (c == 1)
      ans += 1;
    if (r == 1)
      ans += 2;
    return;
  }
  long long mid = (long long)(pow(2.0, (double)n)) / 2;
  long long tile = mid * mid;
  if (r >= mid)
  {
    ans += tile * 2;
    r -= mid;
  }
  if (c >= mid)
  {
    ans += tile;
    c -= mid;
  }
  z(n - 1, r, c);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, r, c;
  cin >> n >> r >> c;
  z(n, r, c);
  cout << ans;
  return 0;
}