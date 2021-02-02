#include <iostream>

using namespace std;

long long n, k, mid;

long long cnt(long long mid)
{
  long long result = 0;
  for (int i = 1; i <= n; i++)
    result += min(mid / i, n);
  return result;
}

int main()
{
  // freopen("input.txt", "r", stdin);

  cin >> n >> k;
  long long ans = 0, s = 0, e = k;
  while (s <= e)
  {
    long long mid = (s + e) / 2;
    if (k > cnt(mid))
      s = mid + 1;
    else
    {
      ans = mid;
      e = mid - 1;
    }
  }
  cout << ans;
  return 0;
}