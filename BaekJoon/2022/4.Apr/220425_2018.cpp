#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int s = n / 2, e = n / 2 + 1;
  int cur = s + e;
  int ans = 1;
  while (s != 0)
  {
    if (cur == n)
    {
      ans++;
    }
    if (e - s == 1)
    {
      s--;
      cur += s;
    }
    else if (cur > n)
    {
      cur -= e;
      e--;
    }
    else if (cur <= n)
    {
      s--;
      cur += s;
    }
  }
  cout << ans;
  return 0;
}