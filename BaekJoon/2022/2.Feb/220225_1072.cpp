#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long x, y;
  cin >> x >> y;

  long long s = 0, e = 1e11;
  long long answer = -1;
  while (s + 1 < e)
  {
    long long mid = (s + e) / 2;
    if (y * 100 / x < (y + mid) * 100 / (x + mid))
    {
      e = mid;
      answer = mid;
    }
    else
    {
      s = mid;
    }
  }
  cout << answer;
  return 0;
}