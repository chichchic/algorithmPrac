#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, temp, cur, curKill = 0, ans = 0;
  cin >> n;
  cin >> cur;
  for (int i = 1; i < n; i++)
  {
    cin >> temp;
    if (cur < temp)
    {
      cur = temp;
      if (ans < curKill)
        ans = curKill;
      curKill = 0;
    }
    else
    {
      curKill++;
    }
  }
  if (ans < curKill)
    ans = curKill;
  cout << ans;
  return 0;
}