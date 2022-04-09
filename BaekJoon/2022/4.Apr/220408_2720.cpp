#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, c, q, d, n, p;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> c;
    q = c / 25;
    c %= 25;
    d = c / 10;
    c %= 10;
    n = c / 5;
    c %= 5;
    p = c;
    cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
  }
  return 0;
}