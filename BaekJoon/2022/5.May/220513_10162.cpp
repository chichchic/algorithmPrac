#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int a, b, c;
  a = t / 300;
  t %= 300;
  b = t / 60;
  t %= 60;
  c = t / 10;
  t %= 10;
  if (t > 0)
  {
    cout << -1;
  }
  else
  {
    cout << a << ' ' << b << ' ' << c;
  }

  return 0;
}